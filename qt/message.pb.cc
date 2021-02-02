// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#include "message.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

namespace aonuo {
class MessageDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<Message> _instance;
} _Message_default_instance_;
}  // namespace aonuo
static void InitDefaultsMessage_message_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::aonuo::_Message_default_instance_;
    new (ptr) ::aonuo::Message();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::aonuo::Message::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<0> scc_info_Message_message_2eproto =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsMessage_message_2eproto}, {}};

void InitDefaults_message_2eproto() {
  ::google::protobuf::internal::InitSCC(&scc_info_Message_message_2eproto.base);
}

::google::protobuf::Metadata file_level_metadata_message_2eproto[1];
const ::google::protobuf::EnumDescriptor* file_level_enum_descriptors_message_2eproto[3];
constexpr ::google::protobuf::ServiceDescriptor const** file_level_service_descriptors_message_2eproto = nullptr;

const ::google::protobuf::uint32 TableStruct_message_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::aonuo::Message, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::aonuo::Message, robotcode_),
  PROTOBUF_FIELD_OFFSET(::aonuo::Message, activetype_),
  PROTOBUF_FIELD_OFFSET(::aonuo::Message, resulttype_),
  PROTOBUF_FIELD_OFFSET(::aonuo::Message, devicetype_),
  PROTOBUF_FIELD_OFFSET(::aonuo::Message, module_),
  PROTOBUF_FIELD_OFFSET(::aonuo::Message, cmd_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::aonuo::Message)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::aonuo::_Message_default_instance_),
};

::google::protobuf::internal::AssignDescriptorsTable assign_descriptors_table_message_2eproto = {
  {}, AddDescriptors_message_2eproto, "message.proto", schemas,
  file_default_instances, TableStruct_message_2eproto::offsets,
  file_level_metadata_message_2eproto, 1, file_level_enum_descriptors_message_2eproto, file_level_service_descriptors_message_2eproto,
};

const char descriptor_table_protodef_message_2eproto[] =
  "\n\rmessage.proto\022\005aonuo\"\256\001\n\007Message\022\021\n\tro"
  "botCode\030\001 \001(\t\022%\n\nactiveType\030\002 \001(\0162\021.aonu"
  "o.ActiveType\022%\n\nresultType\030\003 \001(\0162\021.aonuo"
  ".ResultType\022%\n\ndeviceType\030\004 \001(\0162\021.aonuo."
  "DeviceType\022\016\n\006module\030\005 \001(\t\022\013\n\003cmd\030\006 \001(\t*"
  "5\n\nResultType\022\013\n\007SUCCESS\020\000\022\013\n\007FAILURE\020\001\022"
  "\r\n\tSYS_ERROR\020\002* \n\nDeviceType\022\007\n\003APP\020\000\022\t\n"
  "\005ROBOT\020\001*-\n\nActiveType\022\010\n\004INIT\020\000\022\n\n\006ACTI"
  "VE\020\001\022\t\n\005CLOSE\020\002b\006proto3"
  ;
::google::protobuf::internal::DescriptorTable descriptor_table_message_2eproto = {
  false, InitDefaults_message_2eproto, 
  descriptor_table_protodef_message_2eproto,
  "message.proto", &assign_descriptors_table_message_2eproto, 343,
};

void AddDescriptors_message_2eproto() {
  static constexpr ::google::protobuf::internal::InitFunc deps[1] =
  {
  };
 ::google::protobuf::internal::AddDescriptors(&descriptor_table_message_2eproto, deps, 0);
}

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_message_2eproto = []() { AddDescriptors_message_2eproto(); return true; }();
namespace aonuo {
const ::google::protobuf::EnumDescriptor* ResultType_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&assign_descriptors_table_message_2eproto);
  return file_level_enum_descriptors_message_2eproto[0];
}
bool ResultType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* DeviceType_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&assign_descriptors_table_message_2eproto);
  return file_level_enum_descriptors_message_2eproto[1];
}
bool DeviceType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* ActiveType_descriptor() {
  ::google::protobuf::internal::AssignDescriptors(&assign_descriptors_table_message_2eproto);
  return file_level_enum_descriptors_message_2eproto[2];
}
bool ActiveType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
      return true;
    default:
      return false;
  }
}


// ===================================================================

void Message::InitAsDefaultInstance() {
}
class Message::HasBitSetters {
 public:
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Message::kRobotCodeFieldNumber;
const int Message::kActiveTypeFieldNumber;
const int Message::kResultTypeFieldNumber;
const int Message::kDeviceTypeFieldNumber;
const int Message::kModuleFieldNumber;
const int Message::kCmdFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Message::Message()
  : ::google::protobuf::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:aonuo.Message)
}
Message::Message(const Message& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  robotcode_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.robotcode().size() > 0) {
    robotcode_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.robotcode_);
  }
  module_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.module().size() > 0) {
    module_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.module_);
  }
  cmd_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.cmd().size() > 0) {
    cmd_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.cmd_);
  }
  ::memcpy(&activetype_, &from.activetype_,
    static_cast<size_t>(reinterpret_cast<char*>(&devicetype_) -
    reinterpret_cast<char*>(&activetype_)) + sizeof(devicetype_));
  // @@protoc_insertion_point(copy_constructor:aonuo.Message)
}

void Message::SharedCtor() {
  ::google::protobuf::internal::InitSCC(
      &scc_info_Message_message_2eproto.base);
  robotcode_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  module_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  cmd_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&activetype_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&devicetype_) -
      reinterpret_cast<char*>(&activetype_)) + sizeof(devicetype_));
}

Message::~Message() {
  // @@protoc_insertion_point(destructor:aonuo.Message)
  SharedDtor();
}

void Message::SharedDtor() {
  robotcode_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  module_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  cmd_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void Message::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const Message& Message::default_instance() {
  ::google::protobuf::internal::InitSCC(&::scc_info_Message_message_2eproto.base);
  return *internal_default_instance();
}


void Message::Clear() {
// @@protoc_insertion_point(message_clear_start:aonuo.Message)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  robotcode_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  module_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  cmd_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&activetype_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&devicetype_) -
      reinterpret_cast<char*>(&activetype_)) + sizeof(devicetype_));
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* Message::_InternalParse(const char* begin, const char* end, void* object,
                  ::google::protobuf::internal::ParseContext* ctx) {
  auto msg = static_cast<Message*>(object);
  ::google::protobuf::int32 size; (void)size;
  int depth; (void)depth;
  ::google::protobuf::uint32 tag;
  ::google::protobuf::internal::ParseFunc parser_till_end; (void)parser_till_end;
  auto ptr = begin;
  while (ptr < end) {
    ptr = ::google::protobuf::io::Parse32(ptr, &tag);
    GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
    switch (tag >> 3) {
      // string robotCode = 1;
      case 1: {
        if (static_cast<::google::protobuf::uint8>(tag) != 10) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ctx->extra_parse_data().SetFieldName("aonuo.Message.robotCode");
        object = msg->mutable_robotcode();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParserUTF8;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheckUTF8(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      // .aonuo.ActiveType activeType = 2;
      case 2: {
        if (static_cast<::google::protobuf::uint8>(tag) != 16) goto handle_unusual;
        ::google::protobuf::uint64 val = ::google::protobuf::internal::ReadVarint(&ptr);
        msg->set_activetype(static_cast<::aonuo::ActiveType>(val));
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        break;
      }
      // .aonuo.ResultType resultType = 3;
      case 3: {
        if (static_cast<::google::protobuf::uint8>(tag) != 24) goto handle_unusual;
        ::google::protobuf::uint64 val = ::google::protobuf::internal::ReadVarint(&ptr);
        msg->set_resulttype(static_cast<::aonuo::ResultType>(val));
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        break;
      }
      // .aonuo.DeviceType deviceType = 4;
      case 4: {
        if (static_cast<::google::protobuf::uint8>(tag) != 32) goto handle_unusual;
        ::google::protobuf::uint64 val = ::google::protobuf::internal::ReadVarint(&ptr);
        msg->set_devicetype(static_cast<::aonuo::DeviceType>(val));
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        break;
      }
      // string module = 5;
      case 5: {
        if (static_cast<::google::protobuf::uint8>(tag) != 42) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ctx->extra_parse_data().SetFieldName("aonuo.Message.module");
        object = msg->mutable_module();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParserUTF8;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheckUTF8(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      // string cmd = 6;
      case 6: {
        if (static_cast<::google::protobuf::uint8>(tag) != 50) goto handle_unusual;
        ptr = ::google::protobuf::io::ReadSize(ptr, &size);
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr);
        ctx->extra_parse_data().SetFieldName("aonuo.Message.cmd");
        object = msg->mutable_cmd();
        if (size > end - ptr + ::google::protobuf::internal::ParseContext::kSlopBytes) {
          parser_till_end = ::google::protobuf::internal::GreedyStringParserUTF8;
          goto string_till_end;
        }
        GOOGLE_PROTOBUF_PARSER_ASSERT(::google::protobuf::internal::StringCheckUTF8(ptr, size, ctx));
        ::google::protobuf::internal::InlineGreedyStringParser(object, ptr, size, ctx);
        ptr += size;
        break;
      }
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->EndGroup(tag);
          return ptr;
        }
        auto res = UnknownFieldParse(tag, {_InternalParse, msg},
          ptr, end, msg->_internal_metadata_.mutable_unknown_fields(), ctx);
        ptr = res.first;
        GOOGLE_PROTOBUF_PARSER_ASSERT(ptr != nullptr);
        if (res.second) return ptr;
      }
    }  // switch
  }  // while
  return ptr;
string_till_end:
  static_cast<::std::string*>(object)->clear();
  static_cast<::std::string*>(object)->reserve(size);
  goto len_delim_till_end;
len_delim_till_end:
  return ctx->StoreAndTailCall(ptr, end, {_InternalParse, msg},
                               {parser_till_end, object}, size);
}
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool Message::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:aonuo.Message)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string robotCode = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (10 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_robotcode()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->robotcode().data(), static_cast<int>(this->robotcode().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "aonuo.Message.robotCode"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .aonuo.ActiveType activeType = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (16 & 0xFF)) {
          int value = 0;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_activetype(static_cast< ::aonuo::ActiveType >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .aonuo.ResultType resultType = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (24 & 0xFF)) {
          int value = 0;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_resulttype(static_cast< ::aonuo::ResultType >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .aonuo.DeviceType deviceType = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (32 & 0xFF)) {
          int value = 0;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_devicetype(static_cast< ::aonuo::DeviceType >(value));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string module = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (42 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_module()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->module().data(), static_cast<int>(this->module().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "aonuo.Message.module"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string cmd = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) == (50 & 0xFF)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_cmd()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->cmd().data(), static_cast<int>(this->cmd().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "aonuo.Message.cmd"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:aonuo.Message)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:aonuo.Message)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void Message::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:aonuo.Message)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string robotCode = 1;
  if (this->robotcode().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->robotcode().data(), static_cast<int>(this->robotcode().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "aonuo.Message.robotCode");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->robotcode(), output);
  }

  // .aonuo.ActiveType activeType = 2;
  if (this->activetype() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      2, this->activetype(), output);
  }

  // .aonuo.ResultType resultType = 3;
  if (this->resulttype() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      3, this->resulttype(), output);
  }

  // .aonuo.DeviceType deviceType = 4;
  if (this->devicetype() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      4, this->devicetype(), output);
  }

  // string module = 5;
  if (this->module().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->module().data(), static_cast<int>(this->module().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "aonuo.Message.module");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->module(), output);
  }

  // string cmd = 6;
  if (this->cmd().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->cmd().data(), static_cast<int>(this->cmd().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "aonuo.Message.cmd");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      6, this->cmd(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:aonuo.Message)
}

::google::protobuf::uint8* Message::InternalSerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:aonuo.Message)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string robotCode = 1;
  if (this->robotcode().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->robotcode().data(), static_cast<int>(this->robotcode().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "aonuo.Message.robotCode");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->robotcode(), target);
  }

  // .aonuo.ActiveType activeType = 2;
  if (this->activetype() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      2, this->activetype(), target);
  }

  // .aonuo.ResultType resultType = 3;
  if (this->resulttype() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      3, this->resulttype(), target);
  }

  // .aonuo.DeviceType deviceType = 4;
  if (this->devicetype() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      4, this->devicetype(), target);
  }

  // string module = 5;
  if (this->module().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->module().data(), static_cast<int>(this->module().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "aonuo.Message.module");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->module(), target);
  }

  // string cmd = 6;
  if (this->cmd().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->cmd().data(), static_cast<int>(this->cmd().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "aonuo.Message.cmd");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        6, this->cmd(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:aonuo.Message)
  return target;
}

size_t Message::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:aonuo.Message)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string robotCode = 1;
  if (this->robotcode().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->robotcode());
  }

  // string module = 5;
  if (this->module().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->module());
  }

  // string cmd = 6;
  if (this->cmd().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->cmd());
  }

  // .aonuo.ActiveType activeType = 2;
  if (this->activetype() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->activetype());
  }

  // .aonuo.ResultType resultType = 3;
  if (this->resulttype() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->resulttype());
  }

  // .aonuo.DeviceType deviceType = 4;
  if (this->devicetype() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->devicetype());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void Message::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:aonuo.Message)
  GOOGLE_DCHECK_NE(&from, this);
  const Message* source =
      ::google::protobuf::DynamicCastToGenerated<Message>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:aonuo.Message)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:aonuo.Message)
    MergeFrom(*source);
  }
}

void Message::MergeFrom(const Message& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:aonuo.Message)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.robotcode().size() > 0) {

    robotcode_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.robotcode_);
  }
  if (from.module().size() > 0) {

    module_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.module_);
  }
  if (from.cmd().size() > 0) {

    cmd_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.cmd_);
  }
  if (from.activetype() != 0) {
    set_activetype(from.activetype());
  }
  if (from.resulttype() != 0) {
    set_resulttype(from.resulttype());
  }
  if (from.devicetype() != 0) {
    set_devicetype(from.devicetype());
  }
}

void Message::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:aonuo.Message)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Message::CopyFrom(const Message& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:aonuo.Message)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Message::IsInitialized() const {
  return true;
}

void Message::Swap(Message* other) {
  if (other == this) return;
  InternalSwap(other);
}
void Message::InternalSwap(Message* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  robotcode_.Swap(&other->robotcode_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  module_.Swap(&other->module_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  cmd_.Swap(&other->cmd_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(activetype_, other->activetype_);
  swap(resulttype_, other->resulttype_);
  swap(devicetype_, other->devicetype_);
}

::google::protobuf::Metadata Message::GetMetadata() const {
  ::google::protobuf::internal::AssignDescriptors(&::assign_descriptors_table_message_2eproto);
  return ::file_level_metadata_message_2eproto[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace aonuo
namespace google {
namespace protobuf {
template<> PROTOBUF_NOINLINE ::aonuo::Message* Arena::CreateMaybeMessage< ::aonuo::Message >(Arena* arena) {
  return Arena::CreateInternal< ::aonuo::Message >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
