/*  PCSX2 - PS2 Emulator for PCs
 *  Copyright (C) 2002-2021 PCSX2 Dev Team
 *
 *  PCSX2 is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU Lesser General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  PCSX2 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with PCSX2.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include <string>
#include <utility>
#include <vector>

#include "GSVector.h"

namespace Threading
{
class ThreadHandle;
}

class GSTexture;
class GSDownloadTexture;

namespace GSCapture
{
	bool BeginCapture(float fps, GSVector2i recommendedResolution, float aspect, std::string filename);
	bool DeliverFrame(GSTexture* stex);
	void EndCapture();

	bool IsCapturing();
	const Threading::ThreadHandle& GetEncoderThreadHandle();
	GSVector2i GetSize();

	std::vector<std::pair<std::string, std::string>> GetVideoCodecList(const char* container);
}; // namespace GSCapture
