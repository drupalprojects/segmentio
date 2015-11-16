<?php

function segmentio_drush_command() {
  $items['segmentio-dl-library'] = array(
    'description' => dt('Download and install Segment PHP client library'),
  );
  return $items;
}

function drush_segmentio_dl_library() {
  $olddir = getcwd();
  $path = $olddir . '/sites/all/libraries';
  $url = 'https://github.com/segmentio/analytics-php/archive/master.zip';
  $filename = basename($url);

  // Create the path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory @path was created', array('@path' => $path)), 'notice');
  }

  drush_op('chdir', drush_tempdir());

  // Download the zip archive
  if (!drush_shell_exec('wget %s', $url)) {
    drush_shell_exec('curl -O %s', $url);
  }
  if (!file_exists($filename)) {
    drush_op('chdir', $olddir);
    return drush_set_error(dt('Unable to download @url', array('@url' => $url)));
  }

  // Decompress the zip archive
  drush_tarball_extract($filename, $path);
  // Remove the zip archive
  drush_op('unlink', $filename);
  // Rename extracted dir
  drush_move_dir($path . '/analytics-php-master', $path . '/segmentio');

  drush_op('chdir', $olddir);
  drush_print('Segment PHP client downloaded and installed.');
}