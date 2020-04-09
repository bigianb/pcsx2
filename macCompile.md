brew install harfbuzz sound-touch portaudio wxmac gtk+3 sdl2 libsamplerate freetype 

make sure on the M1 mac you are running Apple silicon - the `arch` command should return arm64.
Note when running VSCode remote the terminal will be x86_64, so type the following in the terminal to switch
`arch -arch arm64e bash -l`

configure in the build dir via
`cmake -D SKIP_POSTPROCESS_BUNDLE=TRUE ..`

The postprocess step breaks code signing which means the build will not run on Apple silicon.

# Raspberry pi

sudo apt-get install libasound2-dev libpcap-dev libxml2-dev gettext liblzma-dev libwxgtk3.0-gtk3-dev libsdl2-dev libharfbuzz-dev libaio-dev libgtk-3-dev libx11-xcb-dev libsoundtouch-dev libsamplerate0-dev portaudio19-dev

By default the compiler on the PI is set to armv6 arch. You need to change that via:
export CFLAGS=-march=armv7

The version of EGL in /opt/vc does not define what we need so we need the version in /usr/include. In absence of a better way, do
sudo mv /opt/vc/include/EGL EGLx

