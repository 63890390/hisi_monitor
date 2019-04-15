#ifndef CONFIG_H_
#define CONFIG_H_

#include <mutex>
#include <string>

#define PIXEL_FORMAT PIXEL_FORMAT_YUV_SEMIPLANAR_420 //ʹ��YUV420P
#define PIC_SIZE PIC_HD1080                          //������й�,��ʹ��SONY MX290,�ֱ���1080P
#define ALIGN 64                                     //Ĭ���ڴ�����С
#define VB_POOLS_NUM 128                             //���������

#ifdef __cplusplus
extern "C"
{
#endif
  extern combo_dev_attr_t KMipiCfg;
#ifdef __cplusplus
}
#endif

namespace nvr
{
struct Config
{
    struct System
    {
        int vb_pools_num;
        System() : vb_pools_num(VB_POOLS_NUM)
        {
        }
    };
    struct Video
    {
        PIC_SIZE_E pic_size;

        Video() : pic_size(PIC_SIZE)
        {
        }
    };

    System system;
    Video video;
    std::mutex mux;

    static Config *Instance()
    {
        static Config *instance = new Config;
        return instance;
    }
};

} // namespace nvr

#endif