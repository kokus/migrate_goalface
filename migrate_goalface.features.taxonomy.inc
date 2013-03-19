<?php
/**
 * @file
 * migrate_goalface.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function migrate_goalface_taxonomy_default_vocabularies() {
  return array(
    'languages' => array(
      'name' => 'Regions',
      'machine_name' => 'regions',
      'description' => 'A list of Regions of the World',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'countries' => array(
      'name' => 'Countries',
      'machine_name' => 'countries',
      'description' => 'A List of Countries of the World',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}