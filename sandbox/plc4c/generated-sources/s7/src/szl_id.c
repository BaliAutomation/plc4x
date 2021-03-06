/*
  Licensed to the Apache Software Foundation (ASF) under one
  or more contributor license agreements.  See the NOTICE file
  distributed with this work for additional information
  regarding copyright ownership.  The ASF licenses this file
  to you under the Apache License, Version 2.0 (the
  "License"); you may not use this file except in compliance
  with the License.  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing,
  software distributed under the License is distributed on an
  "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
  KIND, either express or implied.  See the License for the
  specific language governing permissions and limitations
  under the License.
*/

#include <stdio.h>
#include <plc4c/spi/read_buffer.h>
#include <plc4c/spi/write_buffer.h>
#include <plc4c/spi/evaluation_helper.h>
#include "szl_id.h"

// Parse function.
plc4c_return_code plc4c_s7_read_write_szl_id_parse(plc4c_spi_read_buffer* buf, plc4c_s7_read_write_szl_id** _message) {
  uint16_t startPos = plc4c_spi_read_get_pos(buf);
  uint16_t curPos;

  // Allocate enough memory to contain this data structure.
  (*_message) = malloc(sizeof(plc4c_s7_read_write_szl_id));
  if(*_message == NULL) {
    return NO_MEMORY;
  }

  // Enum field (typeClass)
  plc4c_s7_read_write_szl_module_type_class typeClass = plc4c_spi_read_byte(buf, 4);
  (*_message)->type_class = typeClass;

  // Simple Field (sublistExtract)
  unsigned int sublistExtract = plc4c_spi_read_unsigned_byte(buf, 4);
  (*_message)->sublist_extract = sublistExtract;

  // Enum field (sublistList)
  plc4c_s7_read_write_szl_sublist sublistList = plc4c_spi_read_byte(buf, 8);
  (*_message)->sublist_list = sublistList;

  return OK;
}

plc4c_return_code plc4c_s7_read_write_szl_id_serialize(plc4c_spi_write_buffer* buf, plc4c_s7_read_write_szl_id* _message) {

  // Enum field (typeClass)
  {
    int _value = _message->type_class;
    plc4c_spi_write_byte(buf, 4, _value);
  }

  // Simple Field (sublistExtract)
  {
    unsigned int _value = _message->sublist_extract;
    plc4c_spi_write_unsigned_byte(buf, 4, _value);
  }

  // Enum field (sublistList)
  {
    int8_t _value = _message->sublist_list;
    plc4c_spi_write_byte(buf, 8, _value);
  }

  return OK;
}

uint8_t plc4c_s7_read_write_szl_id_length_in_bytes(plc4c_s7_read_write_szl_id* _message) {
  return plc4c_s7_read_write_szl_id_length_in_bits(_message) / 8;
}

uint8_t plc4c_s7_read_write_szl_id_length_in_bits(plc4c_s7_read_write_szl_id* _message) {
  uint8_t lengthInBits = 0;

  // Enum Field (typeClass)
  lengthInBits += 4;

  // Simple field (sublistExtract)
  lengthInBits += 4;

  // Enum Field (sublistList)
  lengthInBits += 8;

  return lengthInBits;
}

