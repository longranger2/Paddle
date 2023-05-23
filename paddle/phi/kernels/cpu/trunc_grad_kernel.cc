// Copyright (c) 2022 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "paddle/phi/kernels/trunc_grad_kernel.h"

#include "paddle/phi/backends/cpu/cpu_context.h"
#include "paddle/phi/core/kernel_registry.h"

namespace phi {

template <typename T, typename Context>
void TruncGradKernel(const Context& dev_ctx,
                     const DenseTensor& out_grad UNUSED,
                     DenseTensor* in_grad) {
  T* dx_data = dev_ctx.template Alloc<T>(in_grad);

  int numel = in_grad->numel();
  memset(dx_data, 0.0, numel * sizeof(T));
}

}  // namespace phi

PD_REGISTER_KERNEL(trunc_grad,
                   CPU,
                   ALL_LAYOUT,
                   phi::TruncGradKernel,
                   float,
                   double,
                   int,
                   int64_t) {}
