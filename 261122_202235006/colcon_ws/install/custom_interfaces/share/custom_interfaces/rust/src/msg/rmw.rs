#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "custom_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_interfaces__msg__Num() -> *const std::ffi::c_void;
}

#[link(name = "custom_interfaces__rosidl_generator_c")]
extern "C" {
    fn custom_interfaces__msg__Num__init(msg: *mut Num) -> bool;
    fn custom_interfaces__msg__Num__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<Num>, size: usize) -> bool;
    fn custom_interfaces__msg__Num__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<Num>);
    fn custom_interfaces__msg__Num__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<Num>, out_seq: *mut rosidl_runtime_rs::Sequence<Num>) -> bool;
}

// Corresponds to custom_interfaces__msg__Num
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Num {

    // This member is not documented.
    #[allow(missing_docs)]
    pub my_num: i64,

}



impl Default for Num {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_interfaces__msg__Num__init(&mut msg as *mut _) {
        panic!("Call to custom_interfaces__msg__Num__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for Num {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__Num__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__Num__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__Num__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for Num {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for Num where Self: Sized {
  const TYPE_NAME: &'static str = "custom_interfaces/msg/Num";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_interfaces__msg__Num() }
  }
}


#[link(name = "custom_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__custom_interfaces__msg__RobotPose() -> *const std::ffi::c_void;
}

#[link(name = "custom_interfaces__rosidl_generator_c")]
extern "C" {
    fn custom_interfaces__msg__RobotPose__init(msg: *mut RobotPose) -> bool;
    fn custom_interfaces__msg__RobotPose__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<RobotPose>, size: usize) -> bool;
    fn custom_interfaces__msg__RobotPose__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<RobotPose>);
    fn custom_interfaces__msg__RobotPose__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<RobotPose>, out_seq: *mut rosidl_runtime_rs::Sequence<RobotPose>) -> bool;
}

// Corresponds to custom_interfaces__msg__RobotPose
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct RobotPose {

    // This member is not documented.
    #[allow(missing_docs)]
    pub x: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub y: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub theta: f64,

}



impl Default for RobotPose {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !custom_interfaces__msg__RobotPose__init(&mut msg as *mut _) {
        panic!("Call to custom_interfaces__msg__RobotPose__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for RobotPose {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__RobotPose__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__RobotPose__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { custom_interfaces__msg__RobotPose__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for RobotPose {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for RobotPose where Self: Sized {
  const TYPE_NAME: &'static str = "custom_interfaces/msg/RobotPose";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__custom_interfaces__msg__RobotPose() }
  }
}


