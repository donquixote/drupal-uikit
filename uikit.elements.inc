<?php
use Drupal\uikit\FormElement\UikitElementTypeInterface;

/**
 * @see _uikit_element_object()
 */
define('UIKIT_ELEMENT_TYPE', 'uikit_element');

/**
 * Implements hook_element_info()
 *
 * @see uikit_element_info()
 */
function uikit_element_info() {
  $types[UIKIT_ELEMENT_TYPE] = array(
    '#input' => TRUE,
    /* @see _uikit_element_value_callback() */
    '#value_callback' => '_uikit_element_value_callback',
    /* @see _uikit_element_process() */
    '#process' => array('_uikit_element_process'),
    /* @see _uikit_element_after_build() */
    # '#after_build' => array('_uikit_element_after_build'),
    /* @see _uikit_element_validate() */
    # '#element_validate' => array('_uikit_element_validate'),
    /* @see _uikit_element_pre_render() */
    '#pre_render' => array('_uikit_element_pre_render'),
    '#tree' => TRUE,
  );
  return $types;
}

/**
 * Value callback for tabledrag element ($element['#value_callback']).
 *
 * @param array $element
 * @param array|bool|null $input
 * @param array $form_state
 *
 * @throws Exception
 * @return array|bool
 */
function _uikit_element_value_callback(array $element, $input = FALSE, array $form_state = array()) {
  return _uikit_element_object($element)->value_callback($element, $input, $form_state);
}

/**
 * Processor callback for tabledrag element ($element['#process']).
 * See form_process_checkboxes() for an example how these processors work.
 *
 * @param array $element
 * @param array $form_state
 * @param array $form
 *
 * @return array
 */
function _uikit_element_process(array $element, array &$form_state, array &$form) {
  return _uikit_element_object($element)->process($element, $form_state, $form);
}

/**
 * Get the object representing the form element type.
 *
 * @param array $element
 *
 * @return UikitElementTypeInterface
 *
 * @throws RuntimeException
 */
function _uikit_element_object(array &$element) {
  if (!isset($element['#uikit_element_object'])) {
    throw new \RuntimeException('Element object missing in element.');
  }
  $object = $element['#uikit_element_object'];
  if (!$object instanceof UikitElementTypeInterface) {
    throw new \RuntimeException('Element object has wrong type.');
  }
  return $object;
}

/**
 * Callback for $element['#pre_render'].
 *
 * @param array $element
 *
 * @throws Exception
 * @return array
 */
function _uikit_element_pre_render(array $element) {
  foreach (array(
    '#uikit_element_object',
    '#uikit_theme_object',
  ) as $key) {
    if (isset($element[$key])) {
      $object = $element[$key];
      if ($object instanceof \Drupal\uikit\FormElement\PreRenderInterface) {
        $element = $object->pre_render($element);
      }
    }
  }
  return $element;
}
