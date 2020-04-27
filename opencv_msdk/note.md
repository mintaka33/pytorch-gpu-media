# notes


## build opencv with MSDK

```bash
cmake -DCMAKE_SHARED_LINKER_FLAGS=-Wl,-Bsymbolic -DINSTALL_CREATE_DISTRIB=ON \
-DWITH_FFMPEG=ON -DBUILD_EXAMPLES=ON -DWITH_MFX=ON -DCMAKE_BUILD_TYPE=Debug \
../../source/opencv-4.3.0
```

```bash
ffmpeg -f lavfi -i testsrc2 -vframes 10 test.264 -y
```

## call stack
```
iHD_drv_video.so!do_exec2(mos_linux_bo * bo, int used, mos_linux_context * ctx, drm_clip_rect_t * cliprects, int num_cliprects, int DR4, unsigned int flags, int * fence) (/home/fresh/data/work/intel_gpu_stack/source/media-driver-intel-media-20.1.1/media_driver/linux/common/os/i915/mos_bufmgr.c:2642)
iHD_drv_video.so!mos_gem_bo_context_exec2(mos_linux_bo * bo, int used, mos_linux_context * ctx, drm_clip_rect_t * cliprects, int num_cliprects, int DR4, unsigned int flags, int * fence) (/home/fresh/data/work/intel_gpu_stack/source/media-driver-intel-media-20.1.1/media_driver/linux/common/os/i915/mos_bufmgr.c:2781)
iHD_drv_video.so!GpuContextSpecific::SubmitCommandBuffer(GpuContextSpecific * const this, PMOS_INTERFACE osInterface, PMOS_COMMAND_BUFFER cmdBuffer, bool nullRendering) (/home/fresh/data/work/intel_gpu_stack/source/media-driver-intel-media-20.1.1/media_driver/linux/common/os/mos_gpucontext_specific.cpp:1112)
iHD_drv_video.so!Mos_Specific_SubmitCommandBuffer(PMOS_INTERFACE pOsInterface, PMOS_COMMAND_BUFFER pCmdBuffer, int32_t bNullRendering) (/home/fresh/data/work/intel_gpu_stack/source/media-driver-intel-media-20.1.1/media_driver/linux/common/os/mos_os_specific.c:4001)
iHD_drv_video.so!CodechalDecodeAvc::DecodePrimitiveLevel(CodechalDecodeAvc * const this) (/home/fresh/data/work/intel_gpu_stack/source/media-driver-intel-media-20.1.1/media_driver/agnostic/common/codec/hal/codechal_decode_avc.cpp:1876)
iHD_drv_video.so!CodechalDecode::Execute(CodechalDecode * const this, void * params) (/home/fresh/data/work/intel_gpu_stack/source/media-driver-intel-media-20.1.1/media_driver/agnostic/common/codec/hal/codechal_decoder.cpp:1284)
iHD_drv_video.so!DdiMediaDecode::EndPicture(DdiMediaDecode * const this, VADriverContextP ctx, VAContextID context) (/home/fresh/data/work/intel_gpu_stack/source/media-driver-intel-media-20.1.1/media_driver/linux/common/codec/ddi/media_ddi_decode_base.cpp:883)
iHD_drv_video.so!DdiDecode_EndPicture(VADriverContextP ctx, VAContextID context) (/home/fresh/data/work/intel_gpu_stack/source/media-driver-intel-media-20.1.1/media_driver/linux/common/codec/ddi/media_libva_decoder.cpp:153)
iHD_drv_video.so!DdiMedia_EndPicture(VADriverContextP ctx, VAContextID context) (/home/fresh/data/work/intel_gpu_stack/source/media-driver-intel-media-20.1.1/media_driver/linux/common/ddi/media_libva.cpp:3575)
libva.so.2!vaEndPicture(VADisplay dpy, VAContextID context) (/home/fresh/data/work/intel_gpu_stack/source/libva-2.7.1/va/va.c:1621)
libmfxhw64.so.1!UMC::LinuxVideoAccelerator::EndFrame(UMC::LinuxVideoAccelerator * const this) (/home/fresh/data/work/intel_gpu_stack/source/MediaSDK-intel-mediasdk-20.1.1/_studio/shared/umc/io/umc_va/src/umc_va_linux.cpp:887)
libmfxhw64.so.1!UMC::DXVASupport<UMC::VATaskSupplier>::DecodePicture(UMC::DXVASupport<UMC::VATaskSupplier> * const this, UMC::H264DecoderFrame * pFrame, int32_t field) (/home/fresh/data/work/intel_gpu_stack/source/MediaSDK-intel-mediasdk-20.1.1/_studio/shared/umc/codec/h264_dec/include/umc_h264_segment_decoder_dxva.h:141)
libmfxhw64.so.1!UMC::VATaskSupplier::CompleteFrame(UMC::VATaskSupplier * const this, UMC::H264DecoderFrame * pFrame, int32_t field) (/home/fresh/data/work/intel_gpu_stack/source/MediaSDK-intel-mediasdk-20.1.1/_studio/shared/umc/codec/h264_dec/src/umc_h264_va_supplier.cpp:318)
libmfxhw64.so.1!UMC::TaskSupplier::AddSlice(UMC::TaskSupplier * const this, UMC::H264Slice * pSlice, bool force) (/home/fresh/data/work/intel_gpu_stack/source/MediaSDK-intel-mediasdk-20.1.1/_studio/shared/umc/codec/h264_dec/src/umc_h264_task_supplier.cpp:3732)
libmfxhw64.so.1!UMC::TaskSupplier::AddOneFrame(UMC::TaskSupplier * const this, UMC::MediaData * pSource) (/home/fresh/data/work/intel_gpu_stack/source/MediaSDK-intel-mediasdk-20.1.1/_studio/shared/umc/codec/h264_dec/src/umc_h264_task_supplier.cpp:3313)
libmfxhw64.so.1!UMC::TaskSupplier::AddSource(UMC::TaskSupplier * const this, UMC::MediaData * pSource) (/home/fresh/data/work/intel_gpu_stack/source/MediaSDK-intel-mediasdk-20.1.1/_studio/shared/umc/codec/h264_dec/src/umc_h264_task_supplier.cpp:3141)
libmfxhw64.so.1!UMC::VATaskSupplier::AddSource(UMC::VATaskSupplier * const this, UMC::MediaData * pSource) (/home/fresh/data/work/intel_gpu_stack/source/MediaSDK-intel-mediasdk-20.1.1/_studio/shared/umc/codec/h264_dec/src/umc_h264_va_supplier.cpp:340)
libmfxhw64.so.1!VideoDECODEH264::DecodeFrameCheck(VideoDECODEH264 * const this, mfxBitstream * bs, mfxFrameSurface1 * surface_work, mfxFrameSurface1 ** surface_out) (/home/fresh/data/work/intel_gpu_stack/source/MediaSDK-intel-mediasdk-20.1.1/_studio/mfx_lib/decode/h264/src/mfx_h264_dec_decode.cpp:1245)
libmfxhw64.so.1!VideoDECODEH264::DecodeFrameCheck(VideoDECODEH264 * const this, mfxBitstream * bs, mfxFrameSurface1 * surface_work, mfxFrameSurface1 ** surface_out, MFX_ENTRY_POINT * pEntryPoint) (/home/fresh/data/work/intel_gpu_stack/source/MediaSDK-intel-mediasdk-20.1.1/_studio/mfx_lib/decode/h264/src/mfx_h264_dec_decode.cpp:1131)
libmfxhw64.so.1!MFXVideoDECODE_DecodeFrameAsync(mfxSession session, mfxBitstream * bs, mfxFrameSurface1 * surface_work, mfxFrameSurface1 ** surface_out, mfxSyncPoint * syncp) (/home/fresh/data/work/intel_gpu_stack/source/MediaSDK-intel-mediasdk-20.1.1/_studio/mfx_lib/shared/src/libmfxsw_decode.cpp:511)
libmfx.so.1!MFXVideoDECODE_DecodeFrameAsync(mfxSession session, mfxBitstream * bs, mfxFrameSurface1 * surface_work, mfxFrameSurface1 ** surface_out, mfxSyncPoint * syncp) (/home/fresh/data/work/intel_gpu_stack/source/MediaSDK-intel-mediasdk-20.1.1/api/mfx_dispatch/linux/mfxvideo_functions.h:75)
libopencv_world.so.4.3!MFXVideoDECODE::DecodeFrameAsync(MFXVideoDECODE * const this, mfxBitstream * bs, mfxFrameSurface1 * surface_work, mfxFrameSurface1 ** surface_out, mfxSyncPoint * syncp) (/opt/intel/mediasdk/include/mfx/mfxvideo++.h:114)
libopencv_world.so.4.3!VideoCapture_IntelMFX::grabFrame(VideoCapture_IntelMFX * const this) (/home/fresh/data/work/intel_gpu_stack/source/opencv-4.3.0/modules/videoio/src/cap_mfx_reader.cpp:160)
libopencv_world.so.4.3!cv::VideoCapture::grab(cv::VideoCapture * const this) (/home/fresh/data/work/intel_gpu_stack/source/opencv-4.3.0/modules/videoio/src/cap.cpp:312)
libopencv_world.so.4.3!cv::VideoCapture::read(cv::VideoCapture * const this, cv::OutputArray image) (/home/fresh/data/work/intel_gpu_stack/source/opencv-4.3.0/modules/videoio/src/cap.cpp:340)
libopencv_world.so.4.3!cv::VideoCapture::operator>>(cv::VideoCapture * const this, cv::Mat & image) (/home/fresh/data/work/intel_gpu_stack/source/opencv-4.3.0/modules/videoio/src/cap.cpp:372)
main(int argc, char ** argv) (/home/fresh/data/work/intel_gpu_stack/source/pytorch-gpu-media/opencv_msdk/decode.cpp:17)
```