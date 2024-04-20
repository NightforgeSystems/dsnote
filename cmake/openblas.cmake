set(openblas_source_url "https://github.com/OpenMathLib/OpenBLAS/releases/download/v0.3.26/OpenBLAS-0.3.26.tar.gz")
set(openblas_checksum "4e6e4f5cb14c209262e33e6816d70221a2fe49eb69eaf0a06f065598ac602c68")

set(openblas_opts
    -DCMAKE_BUILD_TYPE=Release
    -DCMAKE_INSTALL_PREFIX=${PROJECT_BINARY_DIR}/external
    -DCMAKE_INSTALL_LIBDIR=${external_lib_dir}
    -DCMAKE_INSTALL_INCLUDEDIR=${external_include_dir}
    -DCMAKE_POSITION_INDEPENDENT_CODE=ON
    -DBUILD_TESTING=OFF
    -DBUILD_WITHOUT_LAPACK=OFF
    -DC_LAPACK=ON
    -DDYNAMIC_ARCH=ON
    -DBUILD_STATIC_LIBS=OFF
    -DBUILD_SHARED_LIBS=ON
)

if(arch_arm32)
    list(APPEND openblas_opts -DTARGET=ARMV7)
elseif(arch_arm64)
    list(APPEND openblas_opts -DTARGET=ARMV8)
endif()

ExternalProject_Add(openblas
    SOURCE_DIR ${external_dir}/openblas
    BINARY_DIR ${PROJECT_BINARY_DIR}/external/openblas
    INSTALL_DIR ${PROJECT_BINARY_DIR}/external
    URL ${openblas_source_url}
    URL_HASH SHA256=${openblas_checksum}
    CMAKE_ARGS ${openblas_opts}
    BUILD_ALWAYS False
)

list(APPEND deps openblas)
