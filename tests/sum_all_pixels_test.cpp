
#include <random>

#include "clesperanto.hpp"


int main(int argc, char **argv)
{
    // Test Initialisation
    using type = float;
    size_t width (10), height (10), depth (10);
    std::array<size_t,3> shape = {width, height, depth};
    std::vector<type> arr_in (width*height*depth);
    std::fill(arr_in.begin(), arr_in.end(), 1.0f);
    std::vector<type> arr_res(1);
    arr_res[0] = 1000.0f;

    // Test Kernel
    cle::Clesperanto cle;
    auto Buffer_A = cle.Push<type>(arr_in, shape);
    auto Buffer_B = cle.Create<type>();
    cle.SumOfAllPixels(Buffer_A, Buffer_B);   
    auto arr_out = cle.Pull<type>(Buffer_B);    

    float difference = std::abs(arr_res[0] - arr_out[0]); 
    return difference > std::numeric_limits<type>::epsilon();
}
