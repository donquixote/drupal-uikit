<?php
use Drupal\uikit\FormElement\Theme\ElementThemeInterface;

/**
 * @param array $vars
 *
 * @return string
 *   Rendered HTML.
 */
function theme_uikit_element(array $vars) {
  $element = $vars['element'];
  if (!isset($element['#uikit_theme_object'])) {
    throw new \RuntimeException('Theme object missing in element.');
  }
  $object = $element['#uikit_theme_object'];
  if (!$object instanceof ElementThemeInterface) {
    throw new \RuntimeException('Theme object has wrong type.');
  }
  return $object->theme($element);
}

/**
 * @param array $vars
 *
 * @return string
 *
 * @see theme_form_element()
 */
function theme_uikit_form_element(array $vars) {
  $element = &$vars['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  $attributes = isset($element['#uikit_container_attributes'])
    ? $element['#uikit_container_attributes']
    : array();

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'][] = 'form-item';
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $output = '<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $vars);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $vars) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $output .= "</div>\n";

  return $output;
}

/**
 * @param array $vars
 *
 * @return string
 *
 * @see theme_form_element()
 */
function theme_uikit_inline_element(array $vars) {
  $element = &$vars['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  $html = $prefix . $element['#children'] . $suffix;

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $html = theme('form_element_label', $vars) . $html;
      break;

    case 'after':
      $html .= theme('form_element_label', $vars);
      break;
  }

  if (!empty($element['#description'])) {
    $html .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  $attributes = isset($element['#uikit_container_attributes'])
    ? $element['#uikit_container_attributes']
    : array();

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'][] = 'form-item';
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $html = '<span' . drupal_attributes($attributes) . '>' . $html . '</span>';

  return $html;
}
