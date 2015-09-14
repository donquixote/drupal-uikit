<?php

namespace Drupal\uikit\FormElement;

interface PreRenderInterface {

  /**
   * @param array $element
   *
   * @return array
   */
  public function pre_render($element);
}
