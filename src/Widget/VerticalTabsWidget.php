<?php

namespace Drupal\uikit\Widget;

class VerticalTabsWidget implements WidgetInterface {

  /**
   * @var array
   */
  private $build = array();

  /**
   * @var WidgetInterface[]
   */
  private $children = array();

  /**
   * @param string $key
   * @param \Drupal\uikit\Widget\WidgetInterface $child
   * @param string $title
   */
  function addChild($key, WidgetInterface $child, $title) {
    $this->children[$key] = $child;
    $this->build[$key] = array(
      '#title' => $title,
      '#type' => 'fieldset',
    );
  }

  /**
   * @return array
   *   A render array.
   */
  function build() {
    $build = $this->build;
    $build['#type'] = 'vertical_tabs';

    foreach ($this->children as $key => $child) {
      $build[$key]['tab_content'] = $child->build();
    }

    return $build;
  }
}
