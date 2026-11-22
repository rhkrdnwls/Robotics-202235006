// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:srv/MoveRobot.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/srv/detail/move_robot__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__srv__MoveRobot__get_type_hash(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0xa7, 0xea, 0xa3, 0xd2, 0x8c, 0x82, 0xb7, 0x88,
      0x72, 0x7c, 0x22, 0x31, 0xab, 0x7b, 0x76, 0xb8,
      0x9e, 0xe0, 0x88, 0x00, 0x12, 0xf7, 0x89, 0x31,
      0xfa, 0x5f, 0x97, 0x31, 0x70, 0xc8, 0xa8, 0xa0,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__srv__MoveRobot_Request__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x39, 0x6a, 0x30, 0xae, 0x9d, 0xd9, 0x1b, 0x66,
      0xd7, 0x95, 0x03, 0x04, 0x1c, 0x61, 0x84, 0x2d,
      0xff, 0x7d, 0x5f, 0x93, 0x87, 0x69, 0x10, 0x50,
      0x53, 0x8a, 0x3d, 0x88, 0x56, 0x03, 0xb5, 0xfb,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__srv__MoveRobot_Response__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x1f, 0x56, 0x5b, 0x09, 0x7e, 0x8f, 0x51, 0x1f,
      0x25, 0x34, 0x6c, 0x96, 0x06, 0xd1, 0x0b, 0xee,
      0xf7, 0xaa, 0x77, 0x51, 0xec, 0x76, 0xfa, 0x47,
      0xb9, 0xbe, 0xa2, 0x9b, 0x2a, 0x6f, 0xc9, 0x5a,
    }};
  return &hash;
}

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__srv__MoveRobot_Event__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x20, 0x64, 0xb8, 0x52, 0x6c, 0x70, 0x7c, 0xe4,
      0x24, 0xca, 0x60, 0xd2, 0xcc, 0x73, 0xf2, 0x2e,
      0x06, 0x88, 0x56, 0x19, 0xdf, 0xdf, 0x1c, 0x36,
      0x96, 0xde, 0xd1, 0x84, 0x6e, 0x4b, 0xec, 0x74,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "custom_interfaces/msg/detail/robot_pose__functions.h"
#include "service_msgs/msg/detail/service_event_info__functions.h"
#include "builtin_interfaces/msg/detail/time__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t builtin_interfaces__msg__Time__EXPECTED_HASH = {1, {
    0xb1, 0x06, 0x23, 0x5e, 0x25, 0xa4, 0xc5, 0xed,
    0x35, 0x09, 0x8a, 0xa0, 0xa6, 0x1a, 0x3e, 0xe9,
    0xc9, 0xb1, 0x8d, 0x19, 0x7f, 0x39, 0x8b, 0x0e,
    0x42, 0x06, 0xce, 0xa9, 0xac, 0xf9, 0xc1, 0x97,
  }};
static const rosidl_type_hash_t custom_interfaces__msg__RobotPose__EXPECTED_HASH = {1, {
    0x1b, 0x40, 0x82, 0xbe, 0x02, 0x69, 0x52, 0xa6,
    0xc5, 0xe7, 0x6a, 0x33, 0xa8, 0x36, 0x82, 0xab,
    0x40, 0x84, 0xe7, 0xf2, 0x6b, 0x5e, 0xfe, 0x67,
    0xe1, 0x3b, 0x10, 0xf1, 0xb0, 0xe2, 0x3c, 0xda,
  }};
static const rosidl_type_hash_t service_msgs__msg__ServiceEventInfo__EXPECTED_HASH = {1, {
    0x41, 0xbc, 0xbb, 0xe0, 0x7a, 0x75, 0xc9, 0xb5,
    0x2b, 0xc9, 0x6b, 0xfd, 0x5c, 0x24, 0xd7, 0xf0,
    0xfc, 0x0a, 0x08, 0xc0, 0xcb, 0x79, 0x21, 0xb3,
    0x37, 0x3c, 0x57, 0x32, 0x34, 0x5a, 0x6f, 0x45,
  }};
#endif

static char custom_interfaces__srv__MoveRobot__TYPE_NAME[] = "custom_interfaces/srv/MoveRobot";
static char builtin_interfaces__msg__Time__TYPE_NAME[] = "builtin_interfaces/msg/Time";
static char custom_interfaces__msg__RobotPose__TYPE_NAME[] = "custom_interfaces/msg/RobotPose";
static char custom_interfaces__srv__MoveRobot_Event__TYPE_NAME[] = "custom_interfaces/srv/MoveRobot_Event";
static char custom_interfaces__srv__MoveRobot_Request__TYPE_NAME[] = "custom_interfaces/srv/MoveRobot_Request";
static char custom_interfaces__srv__MoveRobot_Response__TYPE_NAME[] = "custom_interfaces/srv/MoveRobot_Response";
static char service_msgs__msg__ServiceEventInfo__TYPE_NAME[] = "service_msgs/msg/ServiceEventInfo";

// Define type names, field names, and default values
static char custom_interfaces__srv__MoveRobot__FIELD_NAME__request_message[] = "request_message";
static char custom_interfaces__srv__MoveRobot__FIELD_NAME__response_message[] = "response_message";
static char custom_interfaces__srv__MoveRobot__FIELD_NAME__event_message[] = "event_message";

static rosidl_runtime_c__type_description__Field custom_interfaces__srv__MoveRobot__FIELDS[] = {
  {
    {custom_interfaces__srv__MoveRobot__FIELD_NAME__request_message, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_interfaces__srv__MoveRobot_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__MoveRobot__FIELD_NAME__response_message, 16, 16},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_interfaces__srv__MoveRobot_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__MoveRobot__FIELD_NAME__event_message, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_interfaces__srv__MoveRobot_Event__TYPE_NAME, 37, 37},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription custom_interfaces__srv__MoveRobot__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__RobotPose__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__MoveRobot_Event__TYPE_NAME, 37, 37},
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__MoveRobot_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__MoveRobot_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__srv__MoveRobot__get_type_description(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__srv__MoveRobot__TYPE_NAME, 31, 31},
      {custom_interfaces__srv__MoveRobot__FIELDS, 3, 3},
    },
    {custom_interfaces__srv__MoveRobot__REFERENCED_TYPE_DESCRIPTIONS, 6, 6},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&custom_interfaces__msg__RobotPose__EXPECTED_HASH, custom_interfaces__msg__RobotPose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = custom_interfaces__msg__RobotPose__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = custom_interfaces__srv__MoveRobot_Event__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = custom_interfaces__srv__MoveRobot_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[4].fields = custom_interfaces__srv__MoveRobot_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[5].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char custom_interfaces__srv__MoveRobot_Request__FIELD_NAME__current_pose[] = "current_pose";
static char custom_interfaces__srv__MoveRobot_Request__FIELD_NAME__distance[] = "distance";

static rosidl_runtime_c__type_description__Field custom_interfaces__srv__MoveRobot_Request__FIELDS[] = {
  {
    {custom_interfaces__srv__MoveRobot_Request__FIELD_NAME__current_pose, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_interfaces__msg__RobotPose__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__MoveRobot_Request__FIELD_NAME__distance, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_DOUBLE,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription custom_interfaces__srv__MoveRobot_Request__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {custom_interfaces__msg__RobotPose__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__srv__MoveRobot_Request__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__srv__MoveRobot_Request__TYPE_NAME, 39, 39},
      {custom_interfaces__srv__MoveRobot_Request__FIELDS, 2, 2},
    },
    {custom_interfaces__srv__MoveRobot_Request__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&custom_interfaces__msg__RobotPose__EXPECTED_HASH, custom_interfaces__msg__RobotPose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = custom_interfaces__msg__RobotPose__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char custom_interfaces__srv__MoveRobot_Response__FIELD_NAME__result_pose[] = "result_pose";
static char custom_interfaces__srv__MoveRobot_Response__FIELD_NAME__success[] = "success";

static rosidl_runtime_c__type_description__Field custom_interfaces__srv__MoveRobot_Response__FIELDS[] = {
  {
    {custom_interfaces__srv__MoveRobot_Response__FIELD_NAME__result_pose, 11, 11},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {custom_interfaces__msg__RobotPose__TYPE_NAME, 31, 31},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__MoveRobot_Response__FIELD_NAME__success, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription custom_interfaces__srv__MoveRobot_Response__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {custom_interfaces__msg__RobotPose__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__srv__MoveRobot_Response__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__srv__MoveRobot_Response__TYPE_NAME, 40, 40},
      {custom_interfaces__srv__MoveRobot_Response__FIELDS, 2, 2},
    },
    {custom_interfaces__srv__MoveRobot_Response__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&custom_interfaces__msg__RobotPose__EXPECTED_HASH, custom_interfaces__msg__RobotPose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = custom_interfaces__msg__RobotPose__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}
// Define type names, field names, and default values
static char custom_interfaces__srv__MoveRobot_Event__FIELD_NAME__info[] = "info";
static char custom_interfaces__srv__MoveRobot_Event__FIELD_NAME__request[] = "request";
static char custom_interfaces__srv__MoveRobot_Event__FIELD_NAME__response[] = "response";

static rosidl_runtime_c__type_description__Field custom_interfaces__srv__MoveRobot_Event__FIELDS[] = {
  {
    {custom_interfaces__srv__MoveRobot_Event__FIELD_NAME__info, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__MoveRobot_Event__FIELD_NAME__request, 7, 7},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {custom_interfaces__srv__MoveRobot_Request__TYPE_NAME, 39, 39},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__MoveRobot_Event__FIELD_NAME__response, 8, 8},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE_BOUNDED_SEQUENCE,
      1,
      0,
      {custom_interfaces__srv__MoveRobot_Response__TYPE_NAME, 40, 40},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription custom_interfaces__srv__MoveRobot_Event__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {builtin_interfaces__msg__Time__TYPE_NAME, 27, 27},
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__RobotPose__TYPE_NAME, 31, 31},
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__MoveRobot_Request__TYPE_NAME, 39, 39},
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__srv__MoveRobot_Response__TYPE_NAME, 40, 40},
    {NULL, 0, 0},
  },
  {
    {service_msgs__msg__ServiceEventInfo__TYPE_NAME, 33, 33},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__srv__MoveRobot_Event__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__srv__MoveRobot_Event__TYPE_NAME, 37, 37},
      {custom_interfaces__srv__MoveRobot_Event__FIELDS, 3, 3},
    },
    {custom_interfaces__srv__MoveRobot_Event__REFERENCED_TYPE_DESCRIPTIONS, 5, 5},
  };
  if (!constructed) {
    assert(0 == memcmp(&builtin_interfaces__msg__Time__EXPECTED_HASH, builtin_interfaces__msg__Time__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = builtin_interfaces__msg__Time__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&custom_interfaces__msg__RobotPose__EXPECTED_HASH, custom_interfaces__msg__RobotPose__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[1].fields = custom_interfaces__msg__RobotPose__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[2].fields = custom_interfaces__srv__MoveRobot_Request__get_type_description(NULL)->type_description.fields;
    description.referenced_type_descriptions.data[3].fields = custom_interfaces__srv__MoveRobot_Response__get_type_description(NULL)->type_description.fields;
    assert(0 == memcmp(&service_msgs__msg__ServiceEventInfo__EXPECTED_HASH, service_msgs__msg__ServiceEventInfo__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[4].fields = service_msgs__msg__ServiceEventInfo__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "RobotPose current_pose\n"
  "float64 distance\n"
  "---\n"
  "RobotPose result_pose\n"
  "bool success";

static char srv_encoding[] = "srv";
static char implicit_encoding[] = "implicit";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__srv__MoveRobot__get_individual_type_description_source(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__srv__MoveRobot__TYPE_NAME, 31, 31},
    {srv_encoding, 3, 3},
    {toplevel_type_raw_source, 79, 79},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__srv__MoveRobot_Request__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__srv__MoveRobot_Request__TYPE_NAME, 39, 39},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__srv__MoveRobot_Response__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__srv__MoveRobot_Response__TYPE_NAME, 40, 40},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__srv__MoveRobot_Event__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__srv__MoveRobot_Event__TYPE_NAME, 37, 37},
    {implicit_encoding, 8, 8},
    {NULL, 0, 0},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__srv__MoveRobot__get_type_description_sources(
  const rosidl_service_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[7];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 7, 7};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__srv__MoveRobot__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *custom_interfaces__msg__RobotPose__get_individual_type_description_source(NULL);
    sources[3] = *custom_interfaces__srv__MoveRobot_Event__get_individual_type_description_source(NULL);
    sources[4] = *custom_interfaces__srv__MoveRobot_Request__get_individual_type_description_source(NULL);
    sources[5] = *custom_interfaces__srv__MoveRobot_Response__get_individual_type_description_source(NULL);
    sources[6] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__srv__MoveRobot_Request__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__srv__MoveRobot_Request__get_individual_type_description_source(NULL),
    sources[1] = *custom_interfaces__msg__RobotPose__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__srv__MoveRobot_Response__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__srv__MoveRobot_Response__get_individual_type_description_source(NULL),
    sources[1] = *custom_interfaces__msg__RobotPose__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__srv__MoveRobot_Event__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[6];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 6, 6};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__srv__MoveRobot_Event__get_individual_type_description_source(NULL),
    sources[1] = *builtin_interfaces__msg__Time__get_individual_type_description_source(NULL);
    sources[2] = *custom_interfaces__msg__RobotPose__get_individual_type_description_source(NULL);
    sources[3] = *custom_interfaces__srv__MoveRobot_Request__get_individual_type_description_source(NULL);
    sources[4] = *custom_interfaces__srv__MoveRobot_Response__get_individual_type_description_source(NULL);
    sources[5] = *service_msgs__msg__ServiceEventInfo__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
