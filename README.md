MT7601u

Monitor Mode Fixes (802.11n / STBC)

1. "initvals.h" — STBC RX never enabled (main fix)
when the AP uses Space-Time Block Coding (STBC) when transmitting to single-antenna clients, sending the same stream across both of its antennas with different encoding. BBP register R3 bit 7 ("STBC_RX_EN") must be set for the baseband to run the Alamouti decoder and reconstruct the stream with a single receive antenna.

2. "init.c" — "NL80211_FEATURE_ACTIVE_MONITOR" removed
removing hardcoded assigned mac address.

3. "mac.c" — FCS-failed frames not tagged
"MT_RXINFO_CRCERR" (RXWI bit 8) was defined but never read.

4. "main.c" — BAR missing from control filter
"MT_RX_FILTR_CFG_BAR" was defined in "regs.h" but omitted from "configure_filter"'s "FIF_CONTROL" mapping. Block ACK Request frames are part of the 802.11n A-MPDU reordering handshake.

---

Overview

This repository contains fixes and modifications for the MT7601U Linux wireless driver, mainly focused on improving monitor mode behavior when capturing modern 802.11n traffic.

The changes address several issues in the original driver that can result in incomplete packet capture, missing frame types, incorrectly handled corrupted frames, or problems receiving traffic when the access point uses Space-Time Block Coding (STBC).

The main issue addressed by these changes is STBC reception.

Some access points use STBC when communicating with clients, including clients equipped with a single receive antenna. Without enabling STBC reception in the MT7601U baseband, traffic using this transmission method may not be decoded correctly by the adapter.

This repository also includes fixes related to monitor mode configuration, frame filtering, CRC/FCS error reporting, and Block ACK Request frame handling.

---

Main Fix: STBC Reception

The most important change is located in:

initvals.h

The MT7601U hardware supports receiving STBC transmissions, but the required baseband setting was not enabled.

STBC, or Space-Time Block Coding, is an 802.11n feature that allows an access point to transmit encoded data across multiple antennas.

A common implementation uses the Alamouti coding scheme, where the same data stream is transmitted using multiple antennas with different encoding patterns. A receiver with fewer antennas can use the encoded signal to reconstruct the original stream.

For the MT7601U baseband to properly process this traffic, the following setting must be enabled:

BBP register R3, bit 7
STBC_RX_EN

Without this bit enabled, the baseband does not run the required STBC/Alamouti decoding process.

Enabling "STBC_RX_EN" allows the adapter to correctly handle supported STBC transmissions, which is especially important when monitoring 802.11n networks using access points with multiple transmit antennas.

---

Monitor Mode

Monitor mode allows a wireless adapter to capture raw 802.11 frames rather than only receiving traffic addressed directly to the adapter.

This is useful for:

- Wireless packet analysis
- Network debugging
- 802.11 protocol research
- Wi-Fi troubleshooting
- Inspecting management and control frames
- Capturing traffic for analysis tools
- Studying 802.11n behavior

The changes in this repository focus on making monitor mode behave more correctly with the MT7601U chipset.

---

Active Monitor Feature Removal

The original driver advertised:

NL80211_FEATURE_ACTIVE_MONITOR

This behavior was removed from the modified driver.

The change avoids the previous handling involving a hardcoded assigned MAC address and allows monitor mode operation to behave more appropriately for the intended use of the adapter.

The modification is located in:

init.c

---

FCS and CRC Error Handling

Wireless packet captures can include frames that fail their Frame Check Sequence (FCS) validation.

These frames may still be useful during wireless analysis because they can provide information about:

- Signal conditions
- Interference
- Packet corruption
- Reception problems
- Nearby transmissions

The MT7601U hardware provides information indicating whether a received frame contains a CRC error.

The relevant flag is:

MT_RXINFO_CRCERR

This corresponds to:

RXWI bit 8

The definition already existed in the driver, but it was not being read and used when processing received frames.

The changes in:

mac.c

ensure that FCS/CRC-failed frames are properly identified instead of being treated without the appropriate error information.

---

Block ACK Request Support

The changes also address missing Block ACK Request (BAR) frame handling.

BAR frames are an important part of the 802.11n A-MPDU aggregation and reordering process.

When using aggregated MAC Protocol Data Units (A-MPDUs), 802.11 devices can transmit multiple frames efficiently as part of aggregated traffic. Block acknowledgment mechanisms are then used to manage acknowledgments and retransmissions.

The driver already defined:

MT_RX_FILTR_CFG_BAR

inside:

regs.h

However, the flag was missing from the mapping used by:

configure_filter

when handling:

FIF_CONTROL

As a result, Block ACK Request frames could be omitted from monitor mode captures even when control frame capture was enabled.

The modification adds the missing BAR filter handling so these frames can be received as expected.

---

Changes Included

The modifications affect the following parts of the driver:

"initvals.h"

Enables STBC reception through:

STBC_RX_EN

This is the main fix and allows the baseband to perform STBC decoding for supported 802.11n transmissions.

---

"init.c"

Removes:

NL80211_FEATURE_ACTIVE_MONITOR

This removes the previous active-monitor behavior involving a hardcoded assigned MAC address.

---

"mac.c"

Adds handling for:

MT_RXINFO_CRCERR

allowing received frames with CRC/FCS errors to be properly identified.

---

"main.c"

Adds the missing:

MT_RX_FILTR_CFG_BAR

handling to the monitor mode control frame filter configuration.

This allows Block ACK Request frames to be included when the appropriate control frame filtering is enabled.

---

Why These Fixes Matter

Modern Wi-Fi traffic can involve features that are not obvious when working only with normal managed-mode connections.

An adapter may appear to work correctly for connecting to an access point while still missing certain types of traffic in monitor mode.

This is particularly relevant when dealing with:

- 802.11n networks
- STBC transmissions
- A-MPDU aggregation
- Block acknowledgment traffic
- Control frame capture
- Corrupted or partially received frames

These changes focus specifically on improving how the MT7601U driver handles those situations.

---

Intended Use

This project is mainly useful for people working with MT7601U-based adapters on Linux who need more complete monitor mode behavior.

Possible use cases include:

- Wi-Fi protocol research
- Wireless debugging
- Packet capture and analysis
- Driver development
- 802.11 experimentation
- Studying 802.11n traffic
- Network troubleshooting
- Testing wireless hardware behavior

---

Hardware

This repository targets wireless adapters based on the:

MediaTek / Ralink MT7601U

chipset.

Different USB adapters may use different antennas, firmware revisions, or board designs, so behavior can vary between devices even when they use the same chipset.

---

Notes

These changes are focused on driver behavior and monitor mode reception.

The main STBC modification enables hardware functionality that is required for the baseband to properly decode supported STBC transmissions.

The other changes improve how monitor mode handles specific frame types and reception errors that were previously ignored, omitted, or incompletely handled.

As with any wireless driver modification, behavior can depend on the kernel version, adapter hardware, firmware, access point configuration, and the specific 802.11 features being used.

---

Summary

This project improves the MT7601U Linux driver's monitor mode behavior by addressing four specific issues:

1. STBC reception was not enabled, preventing proper decoding of supported STBC transmissions.
2. Active monitor mode support was removed, avoiding the previous hardcoded MAC address behavior.
3. CRC/FCS-failed frames were not properly tagged, despite the hardware exposing the relevant error information.
4. Block ACK Request frames were missing from the control frame filter, resulting in incomplete handling of part of the 802.11n aggregation handshake.

The primary change is enabling "STBC_RX_EN", allowing the MT7601U baseband to perform the required decoding for STBC transmissions.
