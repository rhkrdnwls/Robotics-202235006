// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:msg/Num.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/msg/detail/num__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__msg__Num__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x03, 0x70, 0xd8, 0x0e, 0xb2, 0xd5, 0x6d, 0x2e,
      0xd0, 0x31, 0x6f, 0xf5, 0x5b, 0x59, 0xc3, 0x10,
      0x3a, 0x97, 0xdc, 0xc5, 0xb1, 0xaa, 0x90, 0x79,
      0x64, 0x07, 0xfa, 0x71, 0xac, 0x46, 0xea, 0x75,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_interfaces__msg__Num__TYPE_NAME[] = "custom_interfaces/msg/Num";

// Define type names, field names, and default values
static char custom_interfaces__msg__Num__FIELD_NAME__my_num[] = "my_num";

static rosidl_runtime_c__type_description__Field custom_interfaces__msg__Num__FIELDS[] = {
  {
    {custom_interfaces__msg__Num__FIELD_NAME__my_num, 6, 6},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_INT64,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__msg__Num__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__msg__Num__TYPE_NAME, 25, 25},
      {custom_interfaces__msg__Num__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "int64 my_num";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__msg__Num__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__msg__Num__TYPE_NAME, 25, 25},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 12, 12},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__msg__Num__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__msg__Num__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
