package ProFTPD::Tests::Commands::RNTO;

use lib qw(t/lib);
use base qw(Test::Unit::TestCase ProFTPD::TestSuite::Child);
use strict;

use File::Path qw(mkpath rmtree);
use File::Spec;
use IO::Handle;

use ProFTPD::TestSuite::FTP;
use ProFTPD::TestSuite::Utils qw(:auth :config :module :running :test :testsuite);

$| = 1;

my $order = 0;

my $TESTS = {
  rnto_ok => {
    order => ++$order,
    test_class => [qw(forking)],
  },

  rnto_fails_login_required => {
    order => ++$order,
    test_class => [qw(forking)],
  },

  rnto_fails_no_rnfr => {
    order => ++$order,
    test_class => [qw(forking)],
  },

  rnto_fails_enoent_no_file => {
    order => ++$order,
    test_class => [qw(forking)],
  },

  rnto_fails_enoent_no_dir => {
    order => ++$order,
    test_class => [qw(forking)],
  },

  rnto_fails_eperm => {
    order => ++$order,
    test_class => [qw(forking)],
  },

  rnto_fails_allow_overwrite => {
    order => ++$order,
    test_class => [qw(forking)],
  },

};

sub new {
  return shift()->SUPER::new(@_);
}

sub list_tests {
  return testsuite_get_runnable_tests($TESTS);
}

sub set_up {
  my $self = shift;

  # Create temporary scratch dir
  eval { mkpath('tmp') };
  if ($@) {
    my $abs_path = File::Spec->rel2abs('tmp');
    die("Can't create dir $abs_path: $@");
  }
}

sub tear_down {
  my $self = shift;
  undef $self;

  # Remove temporary scratch dir
  eval { rmtree('tmp') };
};

sub rnto_ok {
  my $self = shift;

  my $config_file = 'tmp/cmds.conf';
  my $pid_file = File::Spec->rel2abs('tmp/cmds.pid');
  my $scoreboard_file = File::Spec->rel2abs('tmp/cmds.scoreboard');
  my $log_file = File::Spec->rel2abs('cmds.log');

  my $auth_user_file = File::Spec->rel2abs('tmp/cmds.passwd');
  my $auth_group_file = File::Spec->rel2abs('tmp/cmds.group');

  my $user = 'proftpd';
  my $passwd = 'test';
  my $home_dir = File::Spec->rel2abs('tmp');

  my $src_file = File::Spec->rel2abs('tmp/foo');
  if (open(my $fh, "> $src_file")) {
    close($fh);

  } else {
    die("Can't open $src_file: $!");
  }

  my $dst_file = File::Spec->rel2abs('tmp/bar');

  auth_user_write($auth_user_file, $user, $passwd, 500, 500, $home_dir,
    '/bin/bash');
  auth_group_write($auth_group_file, 'ftpd', 500, $user);

  my $config = {
    PidFile => $pid_file,
    ScoreboardFile => $scoreboard_file,
    SystemLog => $log_file,

    AuthUserFile => $auth_user_file,
    AuthGroupFile => $auth_group_file,

    IfModules => {
      'mod_delay.c' => {
        DelayEngine => 'off',
      },
    },
  };

  my ($port, $config_user, $config_group) = config_write($config_file, $config);

  # Open pipes, for use between the parent and child processes.  Specifically,
  # the child will indicate when it's done with its test by writing a message
  # to the parent.
  my ($readh, $writeh);
  unless (pipe($readh, $writeh)) {
    die("Can't open pipe: $!");
  }

  $writeh->autoflush(1);

  my $ex;

  # Fork child
  $self->handle_sigchld();
  defined(my $pid = fork()) or die("Can't fork: $!");
  if ($pid) {
    eval {
      my $client = ProFTPD::TestSuite::FTP->new('127.0.0.1', $port);

      eval { $client->login($user, $passwd) };
      if ($@) {
        my $err = $@;
        print $writeh "done\n";
        die("Failed to log in: $err");
      }

      my ($resp_code, $resp_msg);
      eval { ($resp_code, $resp_msg) = $client->rnfr($src_file) };
      if ($@) {
        my $err = $@;
        print $writeh "done\n";
        die("Failed to RNFR: $err");
      }

      eval { ($resp_code, $resp_msg) = $client->rnto($dst_file) };
      if ($@) {
        my $err = $@;
        print $writeh "done\n";
        die("Failed to RNTO: $err");
      }

      my $expected;

      $expected = 250;
      $self->assert($expected == $resp_code,
        test_msg("Expected $expected, got $resp_code"));

      $expected = "Rename successful";
      chomp($resp_msg);
      $self->assert($expected eq $resp_msg,
        test_msg("Expected '$expected', got '$resp_msg'"));
    };

    if ($@) {
      $ex = $@;
    }

    print $writeh "done\n";

  } else {
    # Start server
    server_start($config_file);

    # Wait until we receive word from the child that it has finished its
    # test.
    while (my $msg = <$readh>) {
      chomp($msg);

      if ($msg eq 'done') {
        last;
      }
    }

    exit 0;
  }

  # Stop server
  server_stop($pid_file);

  $self->assert_child_ok($pid);

  if ($ex) {
    die($ex);
  }

  unlink($log_file);
}

sub rnto_fails_login_required {
  my $self = shift;

  my $config_file = 'tmp/cmds.conf';
  my $pid_file = File::Spec->rel2abs('tmp/cmds.pid');
  my $scoreboard_file = File::Spec->rel2abs('tmp/cmds.scoreboard');
  my $log_file = File::Spec->rel2abs('cmds.log');

  my $auth_user_file = File::Spec->rel2abs('tmp/cmds.passwd');
  my $auth_group_file = File::Spec->rel2abs('tmp/cmds.group');

  my $user = 'proftpd';
  my $passwd = 'test';
  my $home_dir = File::Spec->rel2abs('tmp');

  my $dst_file = File::Spec->rel2abs('tmp/bar');

  auth_user_write($auth_user_file, $user, $passwd, 500, 500, $home_dir,
    '/bin/bash');
  auth_group_write($auth_group_file, 'ftpd', 500, $user);

  my $config = {
    PidFile => $pid_file,
    ScoreboardFile => $scoreboard_file,
    SystemLog => $log_file,

    AuthUserFile => $auth_user_file,
    AuthGroupFile => $auth_group_file,

    IfModules => {
      'mod_delay.c' => {
        DelayEngine => 'off',
      },
    },
  };

  my ($port, $config_user, $config_group) = config_write($config_file, $config);

  # Open pipes, for use between the parent and child processes.  Specifically,
  # the child will indicate when it's done with its test by writing a message
  # to the parent.
  my ($readh, $writeh);
  unless (pipe($readh, $writeh)) {
    die("Can't open pipe: $!");
  }

  $writeh->autoflush(1);

  my $ex;

  # Fork child
  $self->handle_sigchld();
  defined(my $pid = fork()) or die("Can't fork: $!");
  if ($pid) {
    eval {
      my $client = ProFTPD::TestSuite::FTP->new('127.0.0.1', $port);

      my ($resp_code, $resp_msg);
      eval { ($resp_code, $resp_msg) = $client->rnfr($dst_file) };
      unless ($@) {
        print $writeh "done\n";
        die("RNFR succeeded unexpectedly");

      } else {
        $resp_code = $client->response_code();
        $resp_msg = $client->response_msg();
      }

      my $expected;

      $expected = 530;
      $self->assert($expected == $resp_code,
        test_msg("Expected $expected, got $resp_code"));

      $expected = "Please login with USER and PASS";
      chomp($resp_msg);
      $self->assert($expected eq $resp_msg,
        test_msg("Expected '$expected', got '$resp_msg'"));
    };

    if ($@) {
      $ex = $@;
    }

    print $writeh "done\n";

  } else {
    # Start server
    server_start($config_file);

    # Wait until we receive word from the child that it has finished its
    # test.
    while (my $msg = <$readh>) {
      chomp($msg);

      if ($msg eq 'done') {
        last;
      }
    }

    exit 0;
  }

  # Stop server
  server_stop($pid_file);

  $self->assert_child_ok($pid);

  if ($ex) {
    die($ex);
  }

  unlink($log_file);
}

sub rnto_fails_no_rnfr {
  my $self = shift;

  my $config_file = 'tmp/cmds.conf';
  my $pid_file = File::Spec->rel2abs('tmp/cmds.pid');
  my $scoreboard_file = File::Spec->rel2abs('tmp/cmds.scoreboard');
  my $log_file = File::Spec->rel2abs('cmds.log');

  my $auth_user_file = File::Spec->rel2abs('tmp/cmds.passwd');
  my $auth_group_file = File::Spec->rel2abs('tmp/cmds.group');

  my $user = 'proftpd';
  my $passwd = 'test';
  my $home_dir = File::Spec->rel2abs('tmp');

  my $dst_file = File::Spec->rel2abs('tmp/foo');

  auth_user_write($auth_user_file, $user, $passwd, 500, 500, $home_dir,
    '/bin/bash');
  auth_group_write($auth_group_file, 'ftpd', 500, $user);

  my $config = {
    PidFile => $pid_file,
    ScoreboardFile => $scoreboard_file,
    SystemLog => $log_file,

    AuthUserFile => $auth_user_file,
    AuthGroupFile => $auth_group_file,

    IfModules => {
      'mod_delay.c' => {
        DelayEngine => 'off',
      },
    },
  };

  my ($port, $config_user, $config_group) = config_write($config_file, $config);

  # Open pipes, for use between the parent and child processes.  Specifically,
  # the child will indicate when it's done with its test by writing a message
  # to the parent.
  my ($readh, $writeh);
  unless (pipe($readh, $writeh)) {
    die("Can't open pipe: $!");
  }

  $writeh->autoflush(1);

  my $ex;

  # Fork child
  $self->handle_sigchld();
  defined(my $pid = fork()) or die("Can't fork: $!");
  if ($pid) {
    eval {
      my $client = ProFTPD::TestSuite::FTP->new('127.0.0.1', $port);

      eval { $client->login($user, $passwd) };
      if ($@) {
        my $err = $@;
        print $writeh "done\n";
        die("Failed to log in: $err");
      }

      my ($resp_code, $resp_msg);
      eval { ($resp_code, $resp_msg) = $client->rnto($dst_file) };
      unless ($@) {
        print $writeh "done\n";
        die("RNFR succeeded unexpectedly");

      } else {
        $resp_code = $client->response_code();
        $resp_msg = $client->response_msg();
      }

      my $expected;

      $expected = 503;
      $self->assert($expected == $resp_code,
        test_msg("Expected $expected, got $resp_code"));

      $expected = "Bad sequence of commands";
      chomp($resp_msg);
      $self->assert($expected eq $resp_msg,
        test_msg("Expected '$expected', got '$resp_msg'"));
    };

    if ($@) {
      $ex = $@;
    }

    print $writeh "done\n";

  } else {
    # Start server
    server_start($config_file);

    # Wait until we receive word from the child that it has finished its
    # test.
    while (my $msg = <$readh>) {
      chomp($msg);

      if ($msg eq 'done') {
        last;
      }
    }

    exit 0;
  }

  # Stop server
  server_stop($pid_file);

  $self->assert_child_ok($pid);

  if ($ex) {
    die($ex);
  }

  unlink($log_file);
}

sub rnto_fails_enoent_no_file {
  my $self = shift;

  my $config_file = 'tmp/cmds.conf';
  my $pid_file = File::Spec->rel2abs('tmp/cmds.pid');
  my $scoreboard_file = File::Spec->rel2abs('tmp/cmds.scoreboard');
  my $log_file = File::Spec->rel2abs('cmds.log');

  my $auth_user_file = File::Spec->rel2abs('tmp/cmds.passwd');
  my $auth_group_file = File::Spec->rel2abs('tmp/cmds.group');

  my $user = 'proftpd';
  my $passwd = 'test';
  my $home_dir = File::Spec->rel2abs('tmp');

  my $src_file = File::Spec->rel2abs('tmp/foo');
  if (open(my $fh, "> $src_file")) {
    close($fh);

  } else {
    die("Can't open $src_file: $!");
  }

  my $dst_file = File::Spec->rel2abs('tmp/bar');

  auth_user_write($auth_user_file, $user, $passwd, 500, 500, $home_dir,
    '/bin/bash');
  auth_group_write($auth_group_file, 'ftpd', 500, $user);

  my $config = {
    PidFile => $pid_file,
    ScoreboardFile => $scoreboard_file,
    SystemLog => $log_file,

    AuthUserFile => $auth_user_file,
    AuthGroupFile => $auth_group_file,

    IfModules => {
      'mod_delay.c' => {
        DelayEngine => 'off',
      },
    },
  };

  my ($port, $config_user, $config_group) = config_write($config_file, $config);

  # Open pipes, for use between the parent and child processes.  Specifically,
  # the child will indicate when it's done with its test by writing a message
  # to the parent.
  my ($readh, $writeh);
  unless (pipe($readh, $writeh)) {
    die("Can't open pipe: $!");
  }

  $writeh->autoflush(1);

  my $ex;

  # Fork child
  $self->handle_sigchld();
  defined(my $pid = fork()) or die("Can't fork: $!");
  if ($pid) {
    eval {
      my $client = ProFTPD::TestSuite::FTP->new('127.0.0.1', $port);

      eval { $client->login($user, $passwd) };
      if ($@) {
        my $err = $@;
        print $writeh "done\n";
        die("Failed to log in: $err");
      }

      my ($resp_code, $resp_msg);
      eval { ($resp_code, $resp_msg) = $client->rnfr($src_file) };
      if ($@) {
        my $err = $@;
        print $writeh "done\n";
        die("Failed to RNFR: $err");
      }

      unlink($src_file);

      eval { ($resp_code, $resp_msg) = $client->rnto($dst_file) };
      unless ($@) {
        print $writeh "done\n";
        die("RNTO succeeded unexpectedly");

      } else {
        $resp_code = $client->response_code();
        $resp_msg = $client->response_msg();
      }

      my $expected;

      $expected = 550;
      $self->assert($expected == $resp_code,
        test_msg("Expected $expected, got $resp_code"));

      $expected = "Rename $dst_file: No such file or directory";
      chomp($resp_msg);
      $self->assert($expected eq $resp_msg,
        test_msg("Expected '$expected', got '$resp_msg'"));
    };

    if ($@) {
      $ex = $@;
    }

    print $writeh "done\n";

  } else {
    # Start server
    server_start($config_file);

    # Wait until we receive word from the child that it has finished its
    # test.
    while (my $msg = <$readh>) {
      chomp($msg);

      if ($msg eq 'done') {
        last;
      }
    }

    exit 0;
  }

  # Stop server
  server_stop($pid_file);

  $self->assert_child_ok($pid);

  if ($ex) {
    die($ex);
  }

  unlink($log_file);
}

sub rnto_fails_enoent_no_dir {
  my $self = shift;

  my $config_file = 'tmp/cmds.conf';
  my $pid_file = File::Spec->rel2abs('tmp/cmds.pid');
  my $scoreboard_file = File::Spec->rel2abs('tmp/cmds.scoreboard');
  my $log_file = File::Spec->rel2abs('cmds.log');

  my $auth_user_file = File::Spec->rel2abs('tmp/cmds.passwd');
  my $auth_group_file = File::Spec->rel2abs('tmp/cmds.group');

  my $user = 'proftpd';
  my $passwd = 'test';
  my $home_dir = File::Spec->rel2abs('tmp');

  my $src_file = File::Spec->rel2abs('tmp/foo');
  if (open(my $fh, "> $src_file")) {
    close($fh);

  } else {
    die("Can't open $src_file: $!");
  }

  my $dst_file = File::Spec->rel2abs('tmp/bar/baz');

  auth_user_write($auth_user_file, $user, $passwd, 500, 500, $home_dir,
    '/bin/bash');
  auth_group_write($auth_group_file, 'ftpd', 500, $user);

  my $config = {
    PidFile => $pid_file,
    ScoreboardFile => $scoreboard_file,
    SystemLog => $log_file,

    AuthUserFile => $auth_user_file,
    AuthGroupFile => $auth_group_file,

    IfModules => {
      'mod_delay.c' => {
        DelayEngine => 'off',
      },
    },
  };

  my ($port, $config_user, $config_group) = config_write($config_file, $config);

  # Open pipes, for use between the parent and child processes.  Specifically,
  # the child will indicate when it's done with its test by writing a message
  # to the parent.
  my ($readh, $writeh);
  unless (pipe($readh, $writeh)) {
    die("Can't open pipe: $!");
  }

  $writeh->autoflush(1);

  my $ex;

  # Fork child
  $self->handle_sigchld();
  defined(my $pid = fork()) or die("Can't fork: $!");
  if ($pid) {
    eval {
      my $client = ProFTPD::TestSuite::FTP->new('127.0.0.1', $port);

      eval { $client->login($user, $passwd) };
      if ($@) {
        my $err = $@;
        print $writeh "done\n";
        die("Failed to log in: $err");
      }

      my ($resp_code, $resp_msg);
      eval { ($resp_code, $resp_msg) = $client->rnfr($src_file) };
      if ($@) {
        my $err = $@;
        print $writeh "done\n";
        die("Failed to RNFR: $err");
      }

      eval { ($resp_code, $resp_msg) = $client->rnto($dst_file) };
      unless ($@) {
        print $writeh "done\n";
        die("RNTO succeeded unexpectedly");

      } else {
        $resp_code = $client->response_code();
        $resp_msg = $client->response_msg();
      }

      my $expected;

      $expected = 550;
      $self->assert($expected == $resp_code,
        test_msg("Expected $expected, got $resp_code"));

      $expected = "Rename $dst_file: No such file or directory";
      chomp($resp_msg);
      $self->assert($expected eq $resp_msg,
        test_msg("Expected '$expected', got '$resp_msg'"));
    };

    if ($@) {
      $ex = $@;
    }

    print $writeh "done\n";

  } else {
    # Start server
    server_start($config_file);

    # Wait until we receive word from the child that it has finished its
    # test.
    while (my $msg = <$readh>) {
      chomp($msg);

      if ($msg eq 'done') {
        last;
      }
    }

    exit 0;
  }

  # Stop server
  server_stop($pid_file);

  $self->assert_child_ok($pid);

  if ($ex) {
    die($ex);
  }

  unlink($log_file);
}

sub rnto_fails_eperm {
  my $self = shift;

  my $config_file = 'tmp/cmds.conf';
  my $pid_file = File::Spec->rel2abs('tmp/cmds.pid');
  my $scoreboard_file = File::Spec->rel2abs('tmp/cmds.scoreboard');
  my $log_file = File::Spec->rel2abs('cmds.log');

  my $auth_user_file = File::Spec->rel2abs('tmp/cmds.passwd');
  my $auth_group_file = File::Spec->rel2abs('tmp/cmds.group');

  my $user = 'proftpd';
  my $passwd = 'test';
  my $home_dir = File::Spec->rel2abs('tmp');

  my $src_file = File::Spec->rel2abs('tmp/foo');
  if (open(my $fh, "> $src_file")) {
    close($fh);

  } else {
    die("Can't open $src_file: $!");
  }

  my $dst_file = File::Spec->rel2abs('tmp/bar');

  auth_user_write($auth_user_file, $user, $passwd, 500, 500, $home_dir,
    '/bin/bash');
  auth_group_write($auth_group_file, 'ftpd', 500, $user);

  my $config = {
    PidFile => $pid_file,
    ScoreboardFile => $scoreboard_file,
    SystemLog => $log_file,

    AuthUserFile => $auth_user_file,
    AuthGroupFile => $auth_group_file,

    IfModules => {
      'mod_delay.c' => {
        DelayEngine => 'off',
      },
    },
  };

  my ($port, $config_user, $config_group) = config_write($config_file, $config);

  # Open pipes, for use between the parent and child processes.  Specifically,
  # the child will indicate when it's done with its test by writing a message
  # to the parent.
  my ($readh, $writeh);
  unless (pipe($readh, $writeh)) {
    die("Can't open pipe: $!");
  }

  $writeh->autoflush(1);

  my $ex;

  # Fork child
  $self->handle_sigchld();
  defined(my $pid = fork()) or die("Can't fork: $!");
  if ($pid) {
    eval {
      my $client = ProFTPD::TestSuite::FTP->new('127.0.0.1', $port);

      eval { $client->login($user, $passwd) };
      if ($@) {
        my $err = $@;
        print $writeh "done\n";
        die("Failed to log in: $err");
      }

      my ($resp_code, $resp_msg);
      eval { ($resp_code, $resp_msg) = $client->rnfr($src_file) };
      if ($@) {
        my $err = $@;
        print $writeh "done\n";
        die("Failed to RNFR: $err");
      }

      chmod(0550, $home_dir);

      eval { ($resp_code, $resp_msg) = $client->rnto($dst_file) };
      unless ($@) {
        print $writeh "done\n";
        die("RNTO succeeded unexpectedly");

      } else {
        $resp_code = $client->response_code();
        $resp_msg = $client->response_msg();
      }

      my $expected;

      $expected = 550;
      $self->assert($expected == $resp_code,
        test_msg("Expected $expected, got $resp_code"));

      $expected = "Rename $dst_file: Permission denied";
      chomp($resp_msg);
      $self->assert($expected eq $resp_msg,
        test_msg("Expected '$expected', got '$resp_msg'"));
    };

    if ($@) {
      $ex = $@;
    }

    print $writeh "done\n";

  } else {
    # Start server
    server_start($config_file);

    # Wait until we receive word from the child that it has finished its
    # test.
    while (my $msg = <$readh>) {
      chomp($msg);

      if ($msg eq 'done') {
        last;
      }
    }

    exit 0;
  }

  # Stop server
  server_stop($pid_file);

  $self->assert_child_ok($pid);

  if ($ex) {
    die($ex);
  }

  unlink($log_file);
}

sub rnto_fails_allow_overwrite {
  my $self = shift;

  my $config_file = 'tmp/cmds.conf';
  my $pid_file = File::Spec->rel2abs('tmp/cmds.pid');
  my $scoreboard_file = File::Spec->rel2abs('tmp/cmds.scoreboard');
  my $log_file = File::Spec->rel2abs('cmds.log');

  my $auth_user_file = File::Spec->rel2abs('tmp/cmds.passwd');
  my $auth_group_file = File::Spec->rel2abs('tmp/cmds.group');

  my $user = 'proftpd';
  my $passwd = 'test';
  my $home_dir = File::Spec->rel2abs('tmp');

  my $src_file = File::Spec->rel2abs('tmp/foo');
  if (open(my $fh, "> $src_file")) {
    close($fh);

  } else {
    die("Can't open $src_file: $!");
  }

  my $dst_file = File::Spec->rel2abs('tmp/bar');
  if (open(my $fh, "> $dst_file")) {
    close($fh);

  } else {
    die("Can't open $dst_file: $!");
  }

  auth_user_write($auth_user_file, $user, $passwd, 500, 500, $home_dir,
    '/bin/bash');
  auth_group_write($auth_group_file, 'ftpd', 500, $user);

  my $config = {
    PidFile => $pid_file,
    ScoreboardFile => $scoreboard_file,
    SystemLog => $log_file,

    AuthUserFile => $auth_user_file,
    AuthGroupFile => $auth_group_file,

    IfModules => {
      'mod_delay.c' => {
        DelayEngine => 'off',
      },
    },
  };

  my ($port, $config_user, $config_group) = config_write($config_file, $config);

  # Open pipes, for use between the parent and child processes.  Specifically,
  # the child will indicate when it's done with its test by writing a message
  # to the parent.
  my ($readh, $writeh);
  unless (pipe($readh, $writeh)) {
    die("Can't open pipe: $!");
  }

  $writeh->autoflush(1);

  my $ex;

  # Fork child
  $self->handle_sigchld();
  defined(my $pid = fork()) or die("Can't fork: $!");
  if ($pid) {
    eval {
      my $client = ProFTPD::TestSuite::FTP->new('127.0.0.1', $port);

      eval { $client->login($user, $passwd) };
      if ($@) {
        my $err = $@;
        print $writeh "done\n";
        die("Failed to log in: $err");
      }

      my ($resp_code, $resp_msg);
      eval { ($resp_code, $resp_msg) = $client->rnfr($src_file) };
      if ($@) {
        my $err = $@;
        print $writeh "done\n";
        die("Failed to RNFR: $err");
      }

      eval { ($resp_code, $resp_msg) = $client->rnto($dst_file) };
      unless ($@) {
        print $writeh "done\n";
        die("RNTO succeeded unexpectedly");

      } else {
        $resp_code = $client->response_code();
        $resp_msg = $client->response_msg();
      }

      my $expected;

      $expected = 550;
      $self->assert($expected == $resp_code,
        test_msg("Expected $expected, got $resp_code"));

      $expected = "$dst_file: Rename permission denied";
      chomp($resp_msg);
      $self->assert($expected eq $resp_msg,
        test_msg("Expected '$expected', got '$resp_msg'"));
    };

    if ($@) {
      $ex = $@;
    }

    print $writeh "done\n";

  } else {
    # Start server
    server_start($config_file);

    # Wait until we receive word from the child that it has finished its
    # test.
    while (my $msg = <$readh>) {
      chomp($msg);

      if ($msg eq 'done') {
        last;
      }
    }

    exit 0;
  }

  # Stop server
  server_stop($pid_file);

  $self->assert_child_ok($pid);

  if ($ex) {
    die($ex);
  }

  unlink($log_file);
}
1;
