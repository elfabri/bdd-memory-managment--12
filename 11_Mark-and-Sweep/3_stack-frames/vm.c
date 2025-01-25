/* we want to make it easier on ourselves
 * to only push frame_t * types onto vm->frames,
 * so we'll write some wrapper functions to help us out.
 *
 * this wrapper functions are: 
 *      vm_frame_push
 *      vm_new_frame
 *      frame_free
 */
#include "vm.h"

void vm_frame_push(vm_t *vm, frame_t *frame) {
  if (vm == NULL || frame == NULL) {
    return;
  }
  stack_push(vm->frames, frame);
}

frame_t *vm_new_frame(vm_t *vm) {
  if (vm == NULL) {
    return NULL;
  }

  frame_t *frame = malloc(sizeof(frame_t));
  if (frame == NULL) {
    return NULL;
  }
  frame->references = stack_new(8);
  vm_frame_push(vm, frame);
  return frame;
}

void frame_free(frame_t *frame) {
  if (frame == NULL) {
    return;
  }
  stack_free(frame->references);
}

// don't touch below this line

vm_t *vm_new() {
  vm_t *vm = malloc(sizeof(vm_t));
  if (vm == NULL) {
    return NULL;
  }

  vm->frames = stack_new(8);
  vm->objects = stack_new(8);
  return vm;
}

void vm_free(vm_t *vm) {
  for (int i = 0; i < vm->frames->count; i++) {
    frame_free(vm->frames->data[i]);
  }
  stack_free(vm->frames);
  stack_free(vm->objects);
  free(vm);
}

