/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: hello_world.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "hello_world.pb-c.h"
void   hello__init
                     (Hello         *message)
{
  static const Hello init_value = HELLO__INIT;
  *message = init_value;
}
size_t hello__get_packed_size
                     (const Hello *message)
{
  assert(message->base.descriptor == &hello__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t hello__pack
                     (const Hello *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &hello__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t hello__pack_to_buffer
                     (const Hello *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &hello__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Hello *
       hello__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Hello *)
     protobuf_c_message_unpack (&hello__descriptor,
                                allocator, len, data);
}
void   hello__free_unpacked
                     (Hello *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &hello__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor hello__field_descriptors[1] =
{
  {
    "hello_target",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_STRING,
    0,   /* quantifier_offset */
    offsetof(Hello, hello_target),
    NULL,
    &protobuf_c_empty_string,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned hello__field_indices_by_name[] = {
  0,   /* field[0] = hello_target */
};
static const ProtobufCIntRange hello__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor hello__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "Hello",
  "Hello",
  "Hello",
  "",
  sizeof(Hello),
  1,
  hello__field_descriptors,
  hello__field_indices_by_name,
  1,  hello__number_ranges,
  (ProtobufCMessageInit) hello__init,
  NULL,NULL,NULL    /* reserved[123] */
};
