<?php

namespace Drupal\uikit\Controller;

interface ControllerInterface {

  /**
   * The main controller method.
   *
   * @return string|array
   */
  function handle();
}
