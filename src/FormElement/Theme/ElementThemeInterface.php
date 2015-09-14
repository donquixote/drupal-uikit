<?php
namespace Drupal\uikit\FormElement\Theme;

interface ElementThemeInterface {

  /**
   * @param array $element
   *   The processed element to be rendered.
   *
   * @return string
   *   Rendered HTML.
   */
  public function theme($element);
}
