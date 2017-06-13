<?php

/**
 * @file
 * Administrative page callbacks for the analyticsjs module.
 */

/**
 * Implements hook_admin_settings().
 */
function segmentio_admin_settings_form($form_state) {
  $form['account'] = array(
    '#type' => 'fieldset',
    '#title' => t('Basic Settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['account']['segmentio_write_key'] = array(
    '#title' => t('Write Key'),
    '#type' => 'textfield',
    '#default_value' => variable_get('segmentio_write_key', ''),
    '#size' => 200,
    '#maxlength' => 200,
    '#required' => TRUE,
    '#description' => t('This Write Key is unique to each Project you have configured in <a href="@segmentio">Segment.io</a>. To get a Write Key, <a href="@analyticsjs">register your Project with Segment.io</a>, or if you already have registered your site, go to your Segment.io Project Settings page.analyticsjs will use this write key to send data to your project.', array('@segmentio' => 'https://segment.io/login', '@analyticsjs' => 'https://segment.io/login')),
  );

  // Advanced segmentio configurations.
  $form['advanced'] = array(
    '#type' => 'fieldset',
    '#title' => t('Advance Configurations'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  // Privacy configurations.
  $form['advanced']['segmentio_privacy'] = array(
    '#type' => 'checkbox',
    '#title' => t('Universal web tracking opt-out'),
    '#description' => t('If enabled and your server receives the <a href="@donottrack">Do-Not-Track</a> header from the client browser, the segmentio module will not embed any tracking code into your site. Compliance with Do Not Track could be purely voluntary, enforced by industry self-regulation, or mandated by state or federal law. Please accept your visitors privacy. If they have opt-out from tracking and advertising, you should accept their personal decision. This feature is currently limited to logged in users and disabled page caching.', array('@donottrack' => 'http://donottrack.us/')),
    '#default_value' => variable_get('segmentio_privacy', 1),
  );

  // Tracking settings
  $form['advanced']['segmentio_track'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Track Settings'),
    '#options' => module_invoke_all('segmentio_info'),
    '#default_value' => variable_get('segmentio_track', array()),
    '#description' => t('Select which additional information should be tracked.'),
  );

  // Tracking enable/disable by Role.
  $form['advanced']['segmentio_roles_block'] = array(
    '#type' => 'checkboxes',
    '#title' => t('User Roles to Not Track'),
    '#options' => user_roles(TRUE),
    '#default_value' => variable_get('segmentio_roles_block', array()),
    '#description' => t('Select which user roles to disable tracking for.'),
  );

  return system_settings_form($form);
}
