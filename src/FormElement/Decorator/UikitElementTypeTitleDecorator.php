<?php

namespace Drupal\uikit\FormElement\Decorator;

use Drupal\uikit\FormElement\UikitElementTypeInterface;

class UikitElementTypeTitleDecorator implements UikitElementTypeInterface {

  /**
   * @var \Drupal\uikit\FormElement\UikitElementTypeInterface
   */
  private $decorated;

  /**
   * @var string
   */
  private $title;

  /**
   * UikitElementTypeTitleDecorator constructor.
   *
   * @param \Drupal\uikit\FormElement\UikitElementTypeInterface $decorated
   * @param $title
   */
  function __construct(UikitElementTypeInterface $decorated, $title) {
    $this->decorated = $decorated;
    $this->title = $title;
  }

  /**
   * @param array $element
   * @param array|FALSE|NULL $input
   * @param array $form_state
   *
   * @return mixed
   *
   * @see _uikit_element_value_callback()
   */
  public function value_callback(array $element, $input, array $form_state) {
    return $this->decorated->value_callback($element, $input, $form_state);
  }

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
  public function process(array $element, array &$form_state, array &$form) {
    if (!isset($element['#title'])) {
      $element['#title'] = $this->title;
    }
    return $this->decorated->process($element, $form_state, $form);
  }
}
