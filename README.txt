Introduction
------------
segmentio for Drupal is the easiest way to integrate segmentio analytics into
your Drupal site.

By installing segmentio's Drupal plugin you can add any analytics service to
your site without touching any code.

segmentio lets you send your analytics data to Google Analytics, Mixpanel,
KISSmetrics, Chartbeat, and more... without having to integrate with each
and every one, saving you time.

Once you're setup, you can swap and add new analytics services with the
click of a button!

Requirements
------------
SegmentIO User Account

Installation
------------
 * Install as usual, Copy the 'segmentio' module directory in to your Drupal,
usually it goes in sites/all/modules.
 * Drush installation : use drush dl segmentio
 * Download Segment analytics-php client from https://github.com/segmentio/analytics-php, extract archive in "sites/all/libraries" and rename dir "analytics-php-master" to "segmentio". After this file "Segment.php" must be available on path "sites/all/libraries/segmentio/lib/Segment.php". Drush users can use the command "drush segmentio-dl-library".

Dependencies
------------
 * Module "Libraries API" - https://www.drupal.org/project/libraries

Configuration
-------------
* Configure user permissions in Administration » People » Permissions:
  - Administer segmentio
    Users with this permission will be able to update your segmentio settings

Using php client library
-------------
* Please use segmentio_load_library function to init Segment. To work with a client's functionality, please use documentation https://segment.com/docs/libraries/php/

Maintainers
-----------
Current maintainers:
 * Gobinath Mallaiyan (gobinathm) - https://drupal.org/user/21629
