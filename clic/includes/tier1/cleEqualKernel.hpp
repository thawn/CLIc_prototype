
#ifndef __cleEqualKernel_hpp
#define __cleEqualKernel_hpp

#include "cleKernel.hpp"

namespace cle
{
    
class EqualKernel : public Kernel
{
private:
    std::string m_OclHeader2d = 
        #include "cle_equal_2d.h" 
        ;
    std::string m_OclHeader3d = 
        #include "cle_equal_3d.h" 
        ;

public:
    EqualKernel(std::shared_ptr<GPU>);
    void SetInput1(Object&);
    void SetInput2(Object&);
    void SetOutput(Object&);
    void Execute();
};

} // namespace cle

#endif // __cleGreaterKernel_hpp
