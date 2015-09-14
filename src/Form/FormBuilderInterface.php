<?php

namespace Drupal\uikit\Form;

interface FormBuilderInterface {

  /**
   * @param array $form
   * @param array $form_state
   *
   * @return array
   *   The form array.
   */
  public function buildForm($form, $form_state);
}
