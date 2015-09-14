<?php

namespace Drupal\uikit\Form;

/**
 * Optional interface for form handler objects.
 */
interface FormSubmitInterface {

  /**
   * Form submit callback.
   *
   * @param array $form
   * @param array $form_state
   */
  function submit(array $form, array &$form_state);

}
