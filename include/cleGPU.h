/**
 * Author: Stephane Rigaud - @strigaud 
 */

#ifndef __cleGPU_h
#define __cleGPU_h

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#include "cleBuffer.h"
#include "cleConfig.h"
#include "image.h"
#include "utils.h"

namespace cle
{
    
/** \class clGPU
* \brief Base class for GPU initialisation and data exchange.
*
* clGPU is the GPU initialisation class which manage the gpu paramters
* like device id, context, and commanq_queue. It remains naive for now.
* clGPU is also the class managing the data exchange between the host 
* and the device with the methods push/pull/create.
*/
class GPU
{

private:
    cl_platform_id platform_id;
    cl_device_id device_id;
    cl_context context;
    cl_command_queue command_queue;

protected:

    void InitialisePlatform();
    void InitialiseDevice();
    void CreateContext();
    void CreateCommandQueue();

public:
    GPU();
    ~GPU(){};

    cl_platform_id GetPlateform();
    cl_device_id GetDevice();
    cl_context GetContext();
    cl_command_queue GetCommandQueue();

};

} // namespace cle

#endif //__clgpu_h