#ifndef CONFIG_H_
#define CONFIG_H_

#include <mutex>
#include <string>

#define PIXEL_FORMAT PIXEL_FORMAT_YUV_SEMIPLANAR_420 //ʹ��YUV420P
#define PIC_SIZE PIC_HD1080                          //������й�,��ʹ��SONY MX290,�ֱ���1080P
#define ALIGN 64                                     //Ĭ���ڴ�����С
#define VB_POOLS_NUM 128                             //���������
#define NVR_ISP_DEV 0                                //ISP�豸
#define NVR_VI_DEV 0                                 //VI�豸
#define NVR_VI_CHN 0                                 //VIͨ��

#ifdef __cplusplus
extern "C"
{
#endif
    extern combo_dev_attr_t KMipiCfg;
    extern ISP_PUB_ATTR_S KISPPubAttr;
    extern VI_DEV_ATTR_S KVIDevAttr;
    extern VI_CHN_ATTR_S KVIChnAttr;
#ifdef __cplusplus
}
#endif

namespace nvr
{
struct Config
{
    struct System
    {
        System()
        {
            font_path = "/nfsroot/msyh.ttc";
            font_size = 32;
        }

        std::string font_path;
        int32_t font_size;
    };
    struct Video
    {
        Video()
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