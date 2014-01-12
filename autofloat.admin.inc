<?php
/**
 * @file
 * The admin settings for the AutoFloat module.
 */

/**
 * Implements hook_settings().
 */
function autofloat_admin_settings() {
  $form['autofloat_start'] = array(
    '#type' => 'radios',
    '#title' => t('Start with the first image on the..'),
    '#options' => array(
      0 => t('right'),
      1 => t('left (swaps "odd" and "even" classes)'),
    ),
    '#default_value' => variable_get('autofloat_start', 0),
    '#description' => t('Re-save existing content to apply changes.'),
  );
  $form['autofloat_css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use autofloat.css'),
    '#default_value' => variable_get('autofloat_css', 1),
    '#description' => t('Uncheck to take care of the floating and margins yourself in custom css.'),
  );
  $form['target_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Selector/rejector settings'),
    '#description' => t('Images will float unless they have the class "nofloat". Re-save existing content to apply changes. Avoid adding classes manually by defining classes here added by other modules/filters. Use your browser inspector to find them.'),
  );
  $form['target_settings']['autofloat_span'] = array(
    '#type' => 'textfield',
    '#title' => t('Additional span classes to float'),
    '#default_value' => variable_get('autofloat_span', 'flickr-wrap'),
    '#description' => t('A "span" with the class "float" will float all containing content, e.g. the image with a caption under it. Optionally define others. Maximum two, divided by a comma. Example: "flickr-wrap".'),
  );
  $form['target_settings']['autofloat_div'] = array(
    '#type' => 'textfield',
    '#title' => t('Additional "div" classes to ignore'),
    '#default_value' => variable_get('autofloat_div', 'flickr-photoset'),
    '#description' => t('Images nested within any element with the class "nofloat" will NOT float, e.g. a set of thumbnails. Optionally define others. Maximum two, divided by a comma. Example: "flickr-photoset".'),
  );

  return system_settings_form($form);
}

/**
 * Validate autofloat settings submission.
 */
function autofloat_admin_settings_validate($form, &$form_state) {
  // Accept maximum two class value for the selector field.
  $limit = $form_state['values']['autofloat_span'];
  if ((substr_count($limit, ',') > 1)) {
    form_set_error('autofloat_span', t('Not more than two values.'));
  }
  // Accept maximum two class value for the rejector field.
  $limit = $form_state['values']['autofloat_div'];
  if ((substr_count($limit, ',') > 1)) {
    form_set_error('autofloat_div', t('Not more than two values.'));
  }
}
