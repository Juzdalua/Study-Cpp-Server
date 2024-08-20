// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/protobuf/compiler/cpp/test_large_enum_value.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_google_2fprotobuf_2fcompiler_2fcpp_2ftest_5flarge_5fenum_5fvalue_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_google_2fprotobuf_2fcompiler_2fcpp_2ftest_5flarge_5fenum_5fvalue_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021003 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_bases.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_google_2fprotobuf_2fcompiler_2fcpp_2ftest_5flarge_5fenum_5fvalue_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_google_2fprotobuf_2fcompiler_2fcpp_2ftest_5flarge_5fenum_5fvalue_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_google_2fprotobuf_2fcompiler_2fcpp_2ftest_5flarge_5fenum_5fvalue_2eproto;
namespace protobuf_unittest {
class TestLargeEnumValue;
struct TestLargeEnumValueDefaultTypeInternal;
extern TestLargeEnumValueDefaultTypeInternal _TestLargeEnumValue_default_instance_;
}  // namespace protobuf_unittest
PROTOBUF_NAMESPACE_OPEN
template<> ::protobuf_unittest::TestLargeEnumValue* Arena::CreateMaybeMessage<::protobuf_unittest::TestLargeEnumValue>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace protobuf_unittest {

enum TestLargeEnumValue_EnumWithLargeValue : int {
  TestLargeEnumValue_EnumWithLargeValue_VALUE_1 = 1,
  TestLargeEnumValue_EnumWithLargeValue_VALUE_MAX = 2147483647
};
bool TestLargeEnumValue_EnumWithLargeValue_IsValid(int value);
constexpr TestLargeEnumValue_EnumWithLargeValue TestLargeEnumValue_EnumWithLargeValue_EnumWithLargeValue_MIN = TestLargeEnumValue_EnumWithLargeValue_VALUE_1;
constexpr TestLargeEnumValue_EnumWithLargeValue TestLargeEnumValue_EnumWithLargeValue_EnumWithLargeValue_MAX = TestLargeEnumValue_EnumWithLargeValue_VALUE_MAX;
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* TestLargeEnumValue_EnumWithLargeValue_descriptor();
template<typename T>
inline const std::string& TestLargeEnumValue_EnumWithLargeValue_Name(T enum_t_value) {
  static_assert(::std::is_same<T, TestLargeEnumValue_EnumWithLargeValue>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function TestLargeEnumValue_EnumWithLargeValue_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    TestLargeEnumValue_EnumWithLargeValue_descriptor(), enum_t_value);
}
inline bool TestLargeEnumValue_EnumWithLargeValue_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, TestLargeEnumValue_EnumWithLargeValue* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<TestLargeEnumValue_EnumWithLargeValue>(
    TestLargeEnumValue_EnumWithLargeValue_descriptor(), name, value);
}
// ===================================================================

class TestLargeEnumValue final :
    public ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase /* @@protoc_insertion_point(class_definition:protobuf_unittest.TestLargeEnumValue) */ {
 public:
  inline TestLargeEnumValue() : TestLargeEnumValue(nullptr) {}
  explicit PROTOBUF_CONSTEXPR TestLargeEnumValue(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  TestLargeEnumValue(const TestLargeEnumValue& from);
  TestLargeEnumValue(TestLargeEnumValue&& from) noexcept
    : TestLargeEnumValue() {
    *this = ::std::move(from);
  }

  inline TestLargeEnumValue& operator=(const TestLargeEnumValue& from) {
    CopyFrom(from);
    return *this;
  }
  inline TestLargeEnumValue& operator=(TestLargeEnumValue&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance);
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const TestLargeEnumValue& default_instance() {
    return *internal_default_instance();
  }
  static inline const TestLargeEnumValue* internal_default_instance() {
    return reinterpret_cast<const TestLargeEnumValue*>(
               &_TestLargeEnumValue_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(TestLargeEnumValue& a, TestLargeEnumValue& b) {
    a.Swap(&b);
  }
  inline void Swap(TestLargeEnumValue* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TestLargeEnumValue* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TestLargeEnumValue* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TestLargeEnumValue>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::CopyFrom;
  inline void CopyFrom(const TestLargeEnumValue& from) {
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::CopyImpl(*this, from);
  }
  using ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::MergeFrom;
  void MergeFrom(const TestLargeEnumValue& from) {
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::MergeImpl(*this, from);
  }
  public:

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "protobuf_unittest.TestLargeEnumValue";
  }
  protected:
  explicit TestLargeEnumValue(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef TestLargeEnumValue_EnumWithLargeValue EnumWithLargeValue;
  static constexpr EnumWithLargeValue VALUE_1 =
    TestLargeEnumValue_EnumWithLargeValue_VALUE_1;
  static constexpr EnumWithLargeValue VALUE_MAX =
    TestLargeEnumValue_EnumWithLargeValue_VALUE_MAX;
  static inline bool EnumWithLargeValue_IsValid(int value) {
    return TestLargeEnumValue_EnumWithLargeValue_IsValid(value);
  }
  static constexpr EnumWithLargeValue EnumWithLargeValue_MIN =
    TestLargeEnumValue_EnumWithLargeValue_EnumWithLargeValue_MIN;
  static constexpr EnumWithLargeValue EnumWithLargeValue_MAX =
    TestLargeEnumValue_EnumWithLargeValue_EnumWithLargeValue_MAX;
  static inline const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor*
  EnumWithLargeValue_descriptor() {
    return TestLargeEnumValue_EnumWithLargeValue_descriptor();
  }
  template<typename T>
  static inline const std::string& EnumWithLargeValue_Name(T enum_t_value) {
    static_assert(::std::is_same<T, EnumWithLargeValue>::value ||
      ::std::is_integral<T>::value,
      "Incorrect type passed to function EnumWithLargeValue_Name.");
    return TestLargeEnumValue_EnumWithLargeValue_Name(enum_t_value);
  }
  static inline bool EnumWithLargeValue_Parse(::PROTOBUF_NAMESPACE_ID::ConstStringParam name,
      EnumWithLargeValue* value) {
    return TestLargeEnumValue_EnumWithLargeValue_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:protobuf_unittest.TestLargeEnumValue)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
  };
  friend struct ::TableStruct_google_2fprotobuf_2fcompiler_2fcpp_2ftest_5flarge_5fenum_5fvalue_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// TestLargeEnumValue

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace protobuf_unittest

PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::protobuf_unittest::TestLargeEnumValue_EnumWithLargeValue> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::protobuf_unittest::TestLargeEnumValue_EnumWithLargeValue>() {
  return ::protobuf_unittest::TestLargeEnumValue_EnumWithLargeValue_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_google_2fprotobuf_2fcompiler_2fcpp_2ftest_5flarge_5fenum_5fvalue_2eproto
