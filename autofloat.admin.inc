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
      1 => t("left (swaps <em>odd</em> and <em>even</em> classes)"),
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
    '#description' => t("Images will float unless they have the class <em>nofloat</em>. <strong>Re-save existing content to apply changes.</strong><br />Avoid adding classes manually by defining classes here added by other modules/filters. Use your browser's inspector to find them."),
  );
  $form['target_settings']['autofloat_span'] = array(
    '#type' => 'textfield',
    '#title' => t("Additional <em>span</em> classes to float"),
    '#default_value' => variable_get('autofloat_span', 'caption'),
    '#description' => t("<strong>A <em>span</em> with the class <em>float</em> will float all containing content</strong>, e.g. the image with a caption under it. <br />Optionally define others. Maximum two, divided by a comma. <br />Example: <em>caption</em>"),
  );
  $form['target_settings']['autofloat_div'] = array(
    '#type' => 'textfield',
    '#title' => t("Additional <em>div</em> classes to ignore"),
    '#default_value' => variable_get('autofloat_div', 'flickr-photoset'),
    '#description' => t("<strong>Images in a <em>div</em> with the class <em>nofloat</em> do NOT float</strong>, e.g. a set of thumbnails. <br />Optionally define others. Maximum two, divided by a comma. <br />Example: <em>flickr-photoset</em>"),
  );

  return system_settings_form($form);
}

/**
 * Implements hook_admin_settings_submit().
 */
function autofloat_admin_settings_submit($form, &$form_state) {
  system_settings_form_submit($form, $form_state);
}
