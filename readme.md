# SnapModbus OFFICIAL

This is the **official** SnapModbus repository starting with release 1.0.1.

Previous releases are available in the <a href="https://sourceforge.net/projects/snapmodbus/files/" target="_blank">SourceForge</a> repository.

The official site is still <a href="https://snapmodbus.sourceforge.io/" target="_blank">here</a>, where you can find a lot of info.

---

To make downloading and compiling more efficient on different operating systems, the package has been split.

You will find the old folders as separate repositories, so you can download only what you are interested in.

This is the list:

| Folder | Repository   |
|----------|------------|
| /SnapModbus/examples   | <a href="https://github.com/davenardella/SnapModbus.examples" target="_blank">SnapModbus.examples</a> |
| /SnapModbus/LabVIEW | <a href="https://github.com/davenardella/SnapModbus.LabVIEW" target="_blank">SnapModbus.LabVIEW</a> |
| /SnapModbus/stress_test | <a href="https://github.com/davenardella/SnapModbus.stress_test" target="_blank">SnapModbus.stress_test</a> |
| /SnapModbus/tools | <a href="https://github.com/davenardella/SnapModbus.tools" target="_blank">SnapModbus.tools</a> |

in <a href="https://github.com/davenardella/SnapModbus.tools" target="_blank">SnapModbus.tools</a> you will find source code and binaries of **WinBroker** and **WinDevice**, here in /tools there are only binaries.

---

## Build SnapModbus

The **/build/bin/win32** and **/build/bin/win64** folders already contain the latest Windows DLLs (and .lib), ready to be used.
For other (*nix) operating systems you need to compile SnapModbus to match your architecture, libc version, etc. 

To do this you need the C++ toolchain, which is usually already included in the distribution.


Otherwise, for example on Linux, you can install it with:

`sudo apt install build-essential`

### *nix OS (Linux, BSD, macOS)

Download and unpack this repository in your home, or use git:

`git clone https://github.com/davenardella/SnapModbus.git`

Enter in the OS folder (SnapModbus/build/< your OS >/), then:

#### Linux:

`make [clean | all | install]`

#### macOS, BSD:

`gmake [clean | all | install]`

>***Note: install switch requires* sudo**

### Windows 

Open the Solution file (/build/windows/VSXXXX/snapmb.sln) with **Visual Studio** (Community Edition is free and fine) then build it.
