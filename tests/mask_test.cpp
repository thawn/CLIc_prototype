
#include <cassert>
#include <random>

#include "clesperanto.hpp"

template <class type>
auto
run_test (const std::array<size_t, 3> &shape, const cl_mem_object_type &mem_type) -> bool
{
    std::vector<type> input1 (shape[0] * shape[1] * shape[2]);
    std::vector<type> input2 (shape[0] * shape[1] * shape[2]);
    std::vector<type> valid (shape[0] * shape[1] * shape[2]);
    static std::uniform_int_distribution<int> distribution (1, 10);
    static std::default_random_engine generator;
    std::generate (input1.begin (), input1.end (), [] () { return static_cast<type> (distribution (generator)); });
    std::fill (input2.begin (), input2.end (), static_cast<type> (0));
    std::fill (valid.begin (), valid.end (), static_cast<type> (0));
    const int center = (shape[0] / 2) + (shape[1] / 2) * shape[0] + (shape[2] / 2) * shape[0] * shape[1];
    valid[center] = input1[center];
    input2[center] = static_cast<type> (1);

    cle::Clesperanto cle;
    cle.GetDevice ()->WaitForKernelToFinish ();
    auto gpu_input1 = cle.Push<type> (input1, shape, mem_type);
    auto gpu_input2 = cle.Push<type> (input2, shape, mem_type);
    auto gpu_output = cle.Create<type> (shape, mem_type);
    cle.Mask (gpu_input1, gpu_input2, gpu_output);
    auto output = cle.Pull<type> (gpu_output);

    return std::equal (output.begin (), output.end (), valid.begin ());
}

auto
main (int argc, char **argv) -> int
{
    assert (run_test<float> ({ 10, 1, 1 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<int> ({ 10, 1, 1 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<unsigned int> ({ 10, 1, 1 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<short> ({ 10, 1, 1 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<unsigned short> ({ 10, 1, 1 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<char> ({ 10, 1, 1 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<unsigned char> ({ 10, 1, 1 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<float> ({ 10, 7, 1 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<int> ({ 10, 7, 1 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<unsigned int> ({ 10, 7, 1 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<short> ({ 10, 7, 1 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<unsigned short> ({ 10, 7, 1 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<char> ({ 10, 7, 1 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<unsigned char> ({ 10, 7, 1 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<float> ({ 10, 7, 5 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<int> ({ 10, 7, 5 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<unsigned int> ({ 10, 7, 5 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<short> ({ 10, 7, 5 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<unsigned short> ({ 10, 7, 5 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<char> ({ 10, 7, 5 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<unsigned char> ({ 10, 7, 5 }, CL_MEM_OBJECT_BUFFER));
    assert (run_test<float> ({ 10, 1, 1 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<int> ({ 10, 1, 1 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<unsigned int> ({ 10, 1, 1 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<short> ({ 10, 1, 1 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<unsigned short> ({ 10, 1, 1 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<char> ({ 10, 1, 1 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<unsigned char> ({ 10, 1, 1 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<float> ({ 10, 7, 1 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<int> ({ 10, 7, 1 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<unsigned int> ({ 10, 7, 1 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<short> ({ 10, 7, 1 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<unsigned short> ({ 10, 7, 1 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<char> ({ 10, 7, 1 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<unsigned char> ({ 10, 7, 1 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<float> ({ 10, 7, 5 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<int> ({ 10, 7, 5 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<unsigned int> ({ 10, 7, 5 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<short> ({ 10, 7, 5 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<unsigned short> ({ 10, 7, 5 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<char> ({ 10, 7, 5 }, CL_MEM_OBJECT_IMAGE1D));
    assert (run_test<unsigned char> ({ 10, 7, 5 }, CL_MEM_OBJECT_IMAGE1D));
    return EXIT_SUCCESS;
}