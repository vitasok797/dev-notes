#ifndef VS_COPY_PROTECTOR_H_
#define VS_COPY_PROTECTOR_H_

namespace vs
{

class CopyProtector final
{
public:
    CopyProtector() = default;

    CopyProtector(const CopyProtector&) = delete;
    CopyProtector& operator=(const CopyProtector&) = delete;

    CopyProtector(CopyProtector&&) noexcept = default;
    CopyProtector& operator=(CopyProtector&&) noexcept = default;

    ~CopyProtector() = default;
};

}  // namespace vs

#endif  // VS_COPY_PROTECTOR_H_
