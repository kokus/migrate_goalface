<?php

/**
 * @file
 *   A GoalFace to Drupal migration.
 */


/*
 * You must implement hook_migrate_api(), setting the API level to 2, for
 * your migration classes to be recognized by the Migrate module.
 */
function migrate_goalface_migrate_api() {
  $api = array(
    'api' => 2,
    'migrations' => array(
    	'RegionTerm' => array('class_name' => 'RegionTermMigration'),
    	'CountryTerm' => array('class_name' => 'CountryTermMigration'),
    ),
  );
  return $api;
}

