#include "tier0.hpp"
#include "tier1.hpp"

#include "utils.hpp"

#include "cle_square_root.h"

namespace cle::tier1
{

auto
square_root_func(const Device::Pointer & device, const Array::Pointer & src, Array::Pointer dst) -> Array::Pointer
{
  tier0::create_like(src, dst, dType::FLOAT);
  const KernelInfo    kernel = { "square_root", kernel::square_root };
  const ParameterList params = { { "src", src }, { "dst", dst } };
  const RangeArray    range = { dst->width(), dst->height(), dst->depth() };
  execute(device, kernel, params, range);
  return dst;
}

} // namespace cle::tier1
