#pragma once

#include "snekobject.h"
#include "stack.h"

typedef struct VirtualMachine {
  stack_t *frames;
  stack_t *objects;
} vm_t;

typedef struct StackFrame {
  stack_t *references;
} frame_t;

/// Our main functions for garbage collection.
void mark(vm_t *vm);
void trace(vm_t *vm);
void sweep(vm_t *vm);

/// This is the function that gets called to actually do the garbage collection,
/// but is just composed of `mark`, `trace`, and `sweep`.
///
/// Don't worry, it's not going to delete your code (hopefully!)
void vm_collect_garbage(vm_t *vm);

/// Already implemented
vm_t *vm_new();
void vm_free(vm_t *vm);
void vm_track_object(vm_t *vm, snek_object_t *obj);

void vm_frame_push(vm_t *vm, frame_t *frame);
frame_t *vm_new_frame(vm_t *vm);

void frame_free(frame_t *frame);

// Marks the object as referenced in the current stack frame.
void frame_reference_object(frame_t *frame, snek_object_t *obj);

