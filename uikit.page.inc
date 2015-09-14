<?php
use Drupal\uikit\Controller\ControllerInterface;

/**
 * Page callback for all uikit pages that are not forms.
 *
 * @param \Drupal\uikit\Controller\ControllerInterface $controller
 *
 * @return string|array
 */
function _uikit_page(ControllerInterface $controller) {
  return $controller->handle();
}
