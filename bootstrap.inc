<?php

/**
 * @file
 * This file should be included by every public-facing page of FlightPath.
 * It will include all the classes, as well as settings and function files, and modules.
 * 
 */


// Note: $levels_deep will have been set (or not) by another script.  This
// is so that you can send "../../" or whatever if you need to.  Currently
// used in routines/routines.php.
if (!isset($levels_deep)) $levels_deep = "";


// Load the includes files, for common functions.
require_once("$levels_deep" . "includes/theme.inc");
require_once("$levels_deep" . "includes/misc.inc");
require_once("$levels_deep" . "includes/forms.inc");
require_once("$levels_deep" . "includes/menu.inc");
require_once("$levels_deep" . "includes/db.inc");

// Should we load the settings file?  This variable should be
// set prior to including this bootstrap file.
if (!isset($skip_flightpath_settings) || $skip_flightpath_settings != TRUE) {
  // Load the global system settings file.
  require_once("$levels_deep" . "custom/settings.php");
}


// Load all of the classes, as well as the custom classes.
require_once("$levels_deep" . "classes/all_classes.php");


// Should we load the settings file?  This variable should be
// set prior to including this bootstrap file.
if (!isset($skip_flightpath_modules) || $skip_flightpath_modules != TRUE) {
  // Include all of the enabled modules
  foreach ($GLOBALS["fp_system_settings"]["modules"] as $module => $value) {
    if (isset($value["enabled"]) && $value["enabled"] != "1") {
      // Module is not enabled.  Skip it.
      continue;
    }
  
    include_module($module, TRUE);
  }
}

// Constants
define('FLIGHTPATH_VERSION', '4.8.2');  // will be replaced automatically by getflightpath.com.
define('FLIGHTPATH_CORE', '4.x');  // hard-coded core version.

define ('WATCHDOG_NOTICE', 5);
define ('WATCHDOG_ALERT', 1);
define ('WATCHDOG_ERROR', 3);
define ('WATCHDOG_DEBUG', 7);

define("MENU_TYPE_NORMAL_ITEM", 1);
define("MENU_TYPE_CALLBACK", 2);
define("MENU_TYPE_TAB", 3);
define("MENU_TYPE_SUB_TAB", 4);

define("MENU_ACCESS_DENIED", 61);
define("MENU_NOT_FOUND", 62);



// Set a global variable which confirms the bootstrap has been loaded.
$GLOBALS["fp_bootstrap_loaded"] = TRUE;
