<?php
/**
 * @file commerce_shipping_weight_tariff.commerce.inc
 * Contains Commerce hook implementations.
 */

/**
 * Implements hook_commerce_product_type_info().
 */
function commerce_shipping_weight_tariff_commerce_product_type_info() {
  $types = array(
    'shipping_tariff' => array(
      'type' => 'shipping_tariff',
      'name' => t('Shipping tariff'),
      'description' => t('A shipping tariff product.'),
      'help' => t('A shipping tariff defines one price point for a particular shipping service.'),
      'revision' => TRUE,
    ),
  );
  return $types;
}

/**
 * Implements hook_commerce_shipping_method_info().
 *
 * Defines our shipping method, that is, the abstract handling of shipping by
 * weight tariffs.
 */
function commerce_shipping_weight_tariff_commerce_shipping_method_info() {
  $shipping_methods['weight_tariff_shipping'] = array(
    'title' => t('Weight tariff shipping'),
    'description' => t('Defines a shipping rate based on weight times a modifier'),
  );

  return $shipping_methods;
}

/**
 * Implements hook_commerce_shipping_service_info().
 */
function commerce_shipping_weight_tariff_commerce_shipping_service_info() {
  // @todo: implement a UI for defining services.
  // @see http://drupal.org/node/1803244
  // In the absence of this, you should create a custom module and define the
  // services for your site in its own implementation of
  // hook_commerce_shipping_service_info, eg Next day, Special delivery, etc.



  $shipping_services = array();
  $shipping_services['mi_servicio_shipping_per_kg'] = array( //arbitrary name w/ 'service' in there
      'title' => t('Fee based on weight'),  //titulo de la interfaz en "shipping" + "shipping services"
      'description' => t('calculate weight based on weight'),
      'display_title' => t('Fee based on weight'),
      'shipping_method' => 'weight_tariff_shipping', //comes from the tariff module...
      'price_component' => 'shipping',  //from commerce_shipping
      'callbacks' => array(
      'rate' => 'commerce_shipping_weight_tariff_service_rate',), //rate callback comes from tariff module
  );

  return $shipping_services;



}
