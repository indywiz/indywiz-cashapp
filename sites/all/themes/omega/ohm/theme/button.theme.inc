<?php

/**
 * Returns HTML for a button form element.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #attributes, #button_type, #name, #value.
 *
 * @ingroup themeable
 */
function ohm_button($variables) {
  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  element_set_attributes($element, array('id', 'name', 'value'));

  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  $element['#attributes']['class'][] = 'button';
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'button--inactive';
  }

  // Catch some primary button functions.
  foreach(array('save', 'new', 'add', 'confirm', 'done', 'submit') as $primary) {
    if(substr_count($element['#id'], $primary)) {
      $element['#attributes']['class'][] = 'button--primary';
    }
  }

  // Catch some negative button functions.
  foreach(array('cancel', 'remove', 'delete') as $negative) {
    if(substr_count($element['#id'], $negative)) {
      $element['#attributes']['class'][] = 'button--negative';
    }
  }

  return '<input' . drupal_attributes($element['#attributes']) . ' />';
}
