install(TARGETS ${info_binary_id} RUNTIME DESTINATION bin)

configure_file("${desktop_dir}/${info_id}.desktop.in" "${PROJECT_BINARY_DIR}/${info_app_icon_id}.desktop")
install(FILES "${PROJECT_BINARY_DIR}/${info_app_icon_id}.desktop" DESTINATION share/applications)

configure_file("${desktop_dir}/${info_id}.metainfo.xml.in" "${PROJECT_BINARY_DIR}/${info_app_icon_id}.metainfo.xml")
install(FILES "${PROJECT_BINARY_DIR}/${info_app_icon_id}.metainfo.xml" DESTINATION share/metainfo)

configure_file("${desktop_dir}/dbus_app.service.in" "${PROJECT_BINARY_DIR}/dbus_app.service")
if(WITH_FLATPAK)
    install(FILES "${PROJECT_BINARY_DIR}/dbus_app.service" DESTINATION share/dbus-1/services RENAME ${info_dbus_app_service}.service)
else()
    install(FILES "${PROJECT_BINARY_DIR}/dbus_app.service" DESTINATION share/dbus-1/services RENAME ${info_binary_id}.service)
endif()

install(FILES "${desktop_dir}/icons/${info_binary_id}.svg" DESTINATION share/icons/hicolor/scalable/apps)
install(FILES "${desktop_dir}/icons/16x16/${info_binary_id}.png" DESTINATION share/icons/hicolor/16x16/apps)
install(FILES "${desktop_dir}/icons/32x32/${info_binary_id}.png" DESTINATION share/icons/hicolor/32x32/apps)
install(FILES "${desktop_dir}/icons/48x48/${info_binary_id}.png" DESTINATION share/icons/hicolor/48x48/apps)
install(FILES "${desktop_dir}/icons/64x64/${info_binary_id}.png" DESTINATION share/icons/hicolor/64x64/apps)
install(FILES "${desktop_dir}/icons/96x96/${info_binary_id}.png" DESTINATION share/icons/hicolor/96x96/apps)
install(FILES "${desktop_dir}/icons/128x128/${info_binary_id}.png" DESTINATION share/icons/hicolor/128x128/apps)
install(FILES "${desktop_dir}/icons/256x256/${info_binary_id}.png" DESTINATION share/icons/hicolor/256x256/apps)
install(FILES "${desktop_dir}/icons/512x512/${info_binary_id}.png" DESTINATION share/icons/hicolor/512x512/apps)

function(check_patchelf)
    if(${patchelf_bin} MATCHES "-NOTFOUND$")
        message(FATAL_ERROR "patchelf not found but it is required to install files")
    endif()
endfunction()

function(strip_all file)
    install(CODE "execute_process(COMMAND ${CMAKE_STRIP} --strip-all ${file})")
endfunction()

function(remove_runpath file)
    check_patchelf()
    install(CODE "execute_process(COMMAND ${patchelf_bin} --remove-rpath ${file})")
endfunction()

function(set_runpath file)
    check_patchelf()
    install(CODE "execute_process(COMMAND ${patchelf_bin} --remove-rpath ${file})")
    install(CODE "execute_process(COMMAND ${patchelf_bin} --set-rpath ${rpath_install_dir} ${file})")
endfunction()

if(BUILD_WHISPERCPP)
    set(whispercpp_ver "1.7.1")
    strip_all("${external_lib_dir}/libwhisper-openblas.so.${whispercpp_ver}")
    set_runpath("${external_lib_dir}/libwhisper-openblas.so.${whispercpp_ver}")
    install(PROGRAMS "${external_lib_dir}/libwhisper-openblas.so.${whispercpp_ver}" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libwhisper-openblas.so.1" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libwhisper-openblas.so" DESTINATION ${lib_install_dir})
    if(${arch_x8664} OR ${arch_arm32})
        strip_all("${external_lib_dir}/libwhisper-fallback.so.${whispercpp_ver}")
        set_runpath("${external_lib_dir}/libwhisper-fallback.so.${whispercpp_ver}")
        install(PROGRAMS "${external_lib_dir}/libwhisper-fallback.so.${whispercpp_ver}" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-fallback.so.1" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-fallback.so" DESTINATION ${lib_install_dir})
    endif()
    if(arch_x8664)
        strip_all("${external_lib_dir}/libwhisper-fallback1.so.${whispercpp_ver}")
        set_runpath("${external_lib_dir}/libwhisper-fallback1.so.${whispercpp_ver}")
        install(PROGRAMS "${external_lib_dir}/libwhisper-fallback1.so.${whispercpp_ver}" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-fallback1.so.1" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-fallback1.so" DESTINATION ${lib_install_dir})
    endif()
    if(BUILD_WHISPERCPP_CLBLAST)
        set(whispercpp_clblast_ver "1.6.2")
        set(clblast_ver "1.6.3")
        strip_all("${external_lib_dir}/libclblast.so.${clblast_ver}")
        strip_all("${external_lib_dir}/libwhisper-clblast.so.${whispercpp_clblast_ver}")
        set_runpath("${external_lib_dir}/libwhisper-clblast.so.${whispercpp_clblast_ver}")
        install(PROGRAMS "${external_lib_dir}/libclblast.so" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libclblast.so.1" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libclblast.so.${clblast_ver}" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-clblast.so.${whispercpp_clblast_ver}" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-clblast.so.1" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-clblast.so" DESTINATION ${lib_install_dir})
    endif()
    if(BUILD_WHISPERCPP_VULKAN)
        strip_all("${external_lib_dir}/libwhisper-vulkan.so.${whispercpp_ver}")
        set_runpath("${external_lib_dir}/libwhisper-vulkan.so.${whispercpp_ver}")
        install(PROGRAMS "${external_lib_dir}/libwhisper-vulkan.so.${whispercpp_ver}" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-vulkan.so.1" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-vulkan.so" DESTINATION ${lib_install_dir})
    endif()
    if(BUILD_WHISPERCPP_CUBLAS)
        strip_all("${external_lib_dir}/libwhisper-cublas.so.${whispercpp_ver}")
        set_runpath("${external_lib_dir}/libwhisper-cublas.so.${whispercpp_ver}")
        install(PROGRAMS "${external_lib_dir}/libwhisper-cublas.so.${whispercpp_ver}" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-cublas.so.1" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-cublas.so" DESTINATION ${lib_install_dir})
    endif()
    if(BUILD_WHISPERCPP_HIPBLAS)
        strip_all("${external_lib_dir}/libwhisper-hipblas.so.${whispercpp_ver}")
        set_runpath("${external_lib_dir}/libwhisper-hipblas.so.${whispercpp_ver}")
        install(PROGRAMS "${external_lib_dir}/libwhisper-hipblas.so.${whispercpp_ver}" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-hipblas.so.1" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-hipblas.so" DESTINATION ${lib_install_dir})
    endif()
    if(BUILD_WHISPERCPP_OPENVINO)
        strip_all("${external_lib_dir}/libwhisper-openvino.so.${whispercpp_ver}")
        set_runpath("${external_lib_dir}/libwhisper-openvino.so.${whispercpp_ver}")
        install(PROGRAMS "${external_lib_dir}/libwhisper-openvino.so.${whispercpp_ver}" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-openvino.so.1" DESTINATION ${lib_install_dir})
        install(PROGRAMS "${external_lib_dir}/libwhisper-openvino.so" DESTINATION ${lib_install_dir})
    endif()
endif()

if(DOWNLOAD_LIBSTT)
    strip_all("${external_lib_dir}/libstt.so")
    strip_all("${external_lib_dir}/libkenlm.so")
    strip_all("${external_lib_dir}/libtensorflowlite.so")
    strip_all("${external_lib_dir}/libtflitedelegates.so")
    set_runpath("${external_lib_dir}/libstt.so")
    set_runpath("${external_lib_dir}/libkenlm.so")
    set_runpath("${external_lib_dir}/libtensorflowlite.so")
    set_runpath("${external_lib_dir}/libtflitedelegates.so")
    install(PROGRAMS "${external_lib_dir}/libstt.so" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libkenlm.so" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libtensorflowlite.so" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libtflitedelegates.so" DESTINATION ${lib_install_dir})
endif()

if(BUILD_OPENBLAS)
    strip_all("${external_lib_dir}/libopenblas.so.0.3")
    set_runpath("${external_lib_dir}/libopenblas.so.0.3")
    install(PROGRAMS "${external_lib_dir}/libopenblas.so.0.3" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libopenblas.so.0" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libopenblas.so" DESTINATION ${lib_install_dir})
endif()

if(BUILD_PIPER OR BUILD_ESPEAK)
    strip_all("${external_bin_dir}/mbrola")
    strip_all("${external_bin_dir}/espeak-ng")
    set_runpath("${external_bin_dir}/mbrola")
    set_runpath("${external_bin_dir}/espeak")
    set_runpath("${external_bin_dir}/espeak-ng")
    install(PROGRAMS "${external_bin_dir}/mbrola" DESTINATION ${bin_install_dir})
    install(PROGRAMS "${external_bin_dir}/espeak" DESTINATION ${bin_install_dir})
    install(PROGRAMS "${external_bin_dir}/espeak-ng" DESTINATION ${bin_install_dir})
    install(DIRECTORY "${external_share_dir}/espeak-ng-data" DESTINATION ${share_install_dir})
endif()

if(BUILD_ESPEAK_MODULE)
    install(FILES "${PROJECT_BINARY_DIR}/espeakdata.tar.xz" DESTINATION ${module_install_dir})
endif()

if(BUILD_RHVOICE)
    strip_all("${external_lib_dir}/libRHVoice_core.so.1.2.2")
    strip_all("${external_lib_dir}/libRHVoice.so.1.2.2")
    set_runpath("${external_lib_dir}/libRHVoice_core.so.1.2.2")
    set_runpath("${external_lib_dir}/libRHVoice.so.1.2.2")
    install(PROGRAMS "${external_lib_dir}/libRHVoice_core.so.1.2.2" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libRHVoice_core.so.1" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libRHVoice_core.so" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libRHVoice.so.1.2.2" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libRHVoice.so.1" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libRHVoice.so" DESTINATION ${lib_install_dir})
endif()
if(BUILD_RHVOICE_MODULE)
    install(FILES "${PROJECT_BINARY_DIR}/rhvoicedata.tar.xz" DESTINATION ${module_install_dir})
    install(FILES "${PROJECT_BINARY_DIR}/rhvoiceconfig.tar.xz" DESTINATION ${module_install_dir})
endif()

if(BUILD_PIPER)
    strip_all("${external_lib_dir}/libonnxruntime.so.1.16.1")
    set_runpath("${external_lib_dir}/libonnxruntime.so.1.16.1")
    install(PROGRAMS "${external_lib_dir}/libonnxruntime.so.1.16.1" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libonnxruntime.so" DESTINATION ${lib_install_dir})
endif()

if(${BUILD_VOSK} OR ${DOWNLOAD_VOSK})
    remove_runpath("${external_lib_dir}/libvosk.so")
    set_runpath("${external_lib_dir}/libvosk.so")
    install(PROGRAMS "${external_lib_dir}/libvosk.so" DESTINATION ${lib_install_dir})
endif()

if(BUILD_BERGAMOT)
    strip_all("${external_lib_dir}/libbergamot_api.so")
    set_runpath("${external_lib_dir}/libbergamot_api.so")
    install(PROGRAMS "${external_lib_dir}/libbergamot_api.so" DESTINATION ${lib_install_dir})
    if(arch_x8664)
        strip_all("${external_lib_dir}/libbergamot_api-fallback.so")
        set_runpath("${external_lib_dir}/libbergamot_api-fallback.so")
        install(PROGRAMS "${external_lib_dir}/libbergamot_api-fallback.so" DESTINATION ${lib_install_dir})
    endif()
endif()

if(BUILD_LIBNUMBERTEXT)
    install(DIRECTORY "${external_share_dir}/libnumbertext" DESTINATION ${share_install_dir})
endif()

if(BUILD_UROMAN)
    if(arch_x8664)
        install(DIRECTORY "${external_share_dir}/uroman" DESTINATION ${share_install_dir})
    endif()
endif()

if(BUILD_APRILASR)
    strip_all("${external_lib_dir}/libaprilasr.so.2023.5.12")
    set_runpath("${external_lib_dir}/libaprilasr.so.2023.5.12")
    install(PROGRAMS "${external_lib_dir}/libaprilasr.so.2023.5.12" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libaprilasr.so.2023" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libaprilasr.so" DESTINATION ${lib_install_dir})
endif()

if(BUILD_ESPEAK)
    strip_all("${external_lib_dir}/libespeak-ng.so.1.1.51")
    set_runpath("${external_lib_dir}/libespeak-ng.so.1.1.51")
    install(PROGRAMS "${external_lib_dir}/libespeak-ng.so.1.1.51" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libespeak-ng.so.1" DESTINATION ${lib_install_dir})
    install(PROGRAMS "${external_lib_dir}/libespeak-ng.so" DESTINATION ${lib_install_dir})
endif()

if(WITH_SYSTEMD_SERVICE)
    configure_file("${systemd_dir}/speech.service.in" "${PROJECT_BINARY_DIR}/speech.service")
    install(FILES "${PROJECT_BINARY_DIR}/speech.service" DESTINATION lib/systemd/user RENAME ${info_binary_id}.service)

    configure_file("${dbus_dir}/dbus_speech.service.in" "${PROJECT_BINARY_DIR}/dbus_speech.service")
    install(FILES "${PROJECT_BINARY_DIR}/dbus_speech.service" DESTINATION share/dbus-1/services RENAME ${info_dbus_service}.service)
endif()

if(BUILD_QQC2_BREEZE_STYLE)
    install(DIRECTORY "${external_lib_dir}/qml" DESTINATION ${lib_install_dir})
    install(DIRECTORY "${external_lib_dir}/plugins" DESTINATION ${lib_install_dir})
endif()
