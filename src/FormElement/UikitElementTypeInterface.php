<?php

namespace Drupal\uikit\FormElement;

/**
 * @see uikit_element_info()
 */
interface UikitElementTypeInterface {

  /**
   * @param array $element
   * @param array|FALSE|NULL $input
   * @param array $form_state
   *
   * @return mixed
   *
   * @see _uikit_element_value_callback()
   */
  public function value_callback(array $element, $input, array $form_state);

  /**
   * @param array $element
   * @param array $form_state
   * @param array $form
   *
   * @return array
   *   The modified form element.
   *
   * @see _uikit_element_process()
   */
  public function process(array $element, array &$form_state, array &$form);

}
