/* Auto-generated table of all pre-included modules, rebuilt
 * by Configure script.  DO NOT EDIT BY HAND
 */

#include "conf.h"

extern module core_module;
extern module xfer_module;
extern module rlimit_module;
extern module auth_unix_module;
extern module auth_file_module;
extern module auth_module;
extern module ls_module;
extern module log_module;
extern module site_module;
extern module delay_module;
extern module facts_module;
extern module dso_module;
extern module readme_module;
extern module auth_pam_module;
extern module tls_module;
extern module proxy_protocol_module;
extern module sftp_module;
extern module ctrls_admin_module;
extern module tls_shmcache_module;
extern module memcache_module;
extern module ctrls_module;
extern module lang_module;
extern module ifsession_module;

module *static_modules[] = {
  &core_module,
  &xfer_module,
  &rlimit_module,
  &auth_unix_module,
  &auth_file_module,
  &auth_module,
  &ls_module,
  &log_module,
  &site_module,
  &delay_module,
  &facts_module,
  &dso_module,
  &readme_module,
  &auth_pam_module,
  &tls_module,
  &proxy_protocol_module,
  &sftp_module,
  &ctrls_admin_module,
  &tls_shmcache_module,
  &memcache_module,
  &ctrls_module,
  &lang_module,
  &ifsession_module,
  NULL
};

module *loaded_modules = NULL;
