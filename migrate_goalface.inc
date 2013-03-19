<?php


class CountryTermMigration extends DynamicMigration {
	
	public function __construct() {
		parent::__construct();

		$this->dependencies = array('RegionTerm');

		$this->description = t('Import country data from goalface database into taxonomy terms.');

		// Define The Source
		$query = Database::getConnection('default', 'goalface')
			->select('country', 'c')
			->fields('c', array('country_id','country_name','priority','region_id'))
			->orderBy('country_id','ASC');

		// Create a MigrateSource object, which manages retrieving the input data.
		$this->source = new MigrateSourceSQL($query);

		// Set up our destination - terms in the  vocabulary
		$this->destination = new MigrateDestinationTerm('countries');

		// Mapping source and destination - primary on source table region to map 
		$this->map = new MigrateSQLMap($this->machineName,
						array(
							'country_id' => array(
								'type' => 'int',
								'length' => 10,
								'not null' => TRUE,
							)
						),
						MigrateDestinationTerm::getKeySchema()
		);

		// Adds all mappings used by migration fields
		$this->addFieldMapping('name', 'country_name');
		$this->addFieldMapping('weight', 'priority');
		$this->addFieldMapping('field_country_region', 'region_id')
				->sourceMigration('RegionTerm')
				->arguments(array('source_type' => 'tid'))
		;

	}
}

class RegionTermMigration extends DynamicMigration {

	public function __construct() {
		parent::__construct();
		$this->description = t('Import region data from goalface database into taxonomy terms.');

		// Define The Source
		$query = Database::getConnection('default', 'goalface')
				->select('region', 'r')
				->fields('r' , array('region_id','region_name','region_fifa'))
				->orderBy('region_id', 'ASC');

		 // Create a MigrateSource object, which manages retrieving the input data.
    	$this->source = new MigrateSourceSQL($query);

    	// Set up our destination - terms in the regions vocabulary
		$this->destination = new MigrateDestinationTerm('regions');


		// Mapping source and destination - primary on source table region to map 
		$this->map = new MigrateSQLMap($this->machineName,
						array(
							'region_id' => array(
								'type' => 'int',
								'length' => 10,
								'not null' => TRUE,
							)
						),
						MigrateDestinationTerm::getKeySchema()
		);


		// Adds all mappings used by migration fields
		$this->addFieldMapping('name', 'region_name');
    	$this->addFieldMapping('field_name_fifa', 'region_fifa');

	}

}

//In Progress
class TeamNodeMigration extends  DynamicMigration {

	public function __construct() {
		parent::__construct();

		$this->dependencies = array('RegionTerm','CountryTerm');

		$this->description = t('Import Team data from goalface database into node of entity team.');

		// Define The Source
		$query = Database::getConnection('default', 'goalface')
				->select()
				->fields()
				->orderBy();
	}	

}

