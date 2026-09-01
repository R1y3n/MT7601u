# MT7601u
# Monitor Mode Fixes (802.11n / STBC)

**1. `initvals.h` — STBC RX never enabled (main fix)**
when the AP uses Space-Time Block Coding (STBC) when transmitting to single-antenna clients, sending the same stream across both of its antennas with different encoding. BBP register R3 bit 7 (`STBC_RX_EN`) must be set for the baseband to run the Alamouti decoder and reconstruct the stream with a single receive antenna.

**2. `init.c` — `NL80211_FEATURE_ACTIVE_MONITOR` removed**
removing hardcoded assigned mac address.

**3. `mac.c` — FCS-failed frames not tagged**
`MT_RXINFO_CRCERR` (RXWI bit 8) was defined but never read.

**4. `main.c` — BAR missing from control filter**
`MT_RX_FILTR_CFG_BAR` was defined in `regs.h` but omitted from `configure_filter`'s `FIF_CONTROL` mapping. Block ACK Request frames are part of the 802.11n A-MPDU reordering handshake.
