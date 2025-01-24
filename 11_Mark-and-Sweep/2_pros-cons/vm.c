/* We'll be using a vm_t struct which stands for
 * Virtual Machine Type. This vm_t simulates
 * what would normally be tracked if Sneklang were
 * a fully functional interpreted language (it's not).
 * This virtual machine is much simpler than a real one
 * because all we care about is demonstrating
 * the garbage collection aspects.
 *
 * On the vm_t there are frames and objects.
 * The frames field holds a stack of frames,
 * which are pushed and popped as we
 * enter and exit new scopes. At each of the
 * scope entrances, a new stack frame is pushed
 * onto the frames stack
 * 
 * The objects field is also a stack,
 * but it holds snek_object_t pointers.
 * 
 */
#include "vm.h"

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
  if (vm == NULL) {
    return;
  }

  if (vm->objects != NULL) {
    stack_free(vm->objects);
  }
  if (vm->frames != NULL) {
    stack_free(vm->frames);
  }

  free(vm);
}

