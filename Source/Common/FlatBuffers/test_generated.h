// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_TEST_H_
#define FLATBUFFERS_GENERATED_TEST_H_

#include "flatbuffers/flatbuffers.h"

struct PlayerInfo;

struct PlayerInfo FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_NAME = 4,
    VT_LEVEL = 6
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  int32_t level() const {
    return GetField<int32_t>(VT_LEVEL, 0);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.Verify(name()) &&
           VerifyField<int32_t>(verifier, VT_LEVEL) &&
           verifier.EndTable();
  }
};

struct PlayerInfoBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(PlayerInfo::VT_NAME, name);
  }
  void add_level(int32_t level) {
    fbb_.AddElement<int32_t>(PlayerInfo::VT_LEVEL, level, 0);
  }
  explicit PlayerInfoBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  PlayerInfoBuilder &operator=(const PlayerInfoBuilder &);
  flatbuffers::Offset<PlayerInfo> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<PlayerInfo>(end);
    return o;
  }
};

inline flatbuffers::Offset<PlayerInfo> CreatePlayerInfo(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    int32_t level = 0) {
  PlayerInfoBuilder builder_(_fbb);
  builder_.add_level(level);
  builder_.add_name(name);
  return builder_.Finish();
}

inline flatbuffers::Offset<PlayerInfo> CreatePlayerInfoDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    int32_t level = 0) {
  return CreatePlayerInfo(
      _fbb,
      name ? _fbb.CreateString(name) : 0,
      level);
}

inline const PlayerInfo *GetPlayerInfo(const void *buf) {
  return flatbuffers::GetRoot<PlayerInfo>(buf);
}

inline const PlayerInfo *GetSizePrefixedPlayerInfo(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<PlayerInfo>(buf);
}

inline bool VerifyPlayerInfoBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<PlayerInfo>(nullptr);
}

inline bool VerifySizePrefixedPlayerInfoBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<PlayerInfo>(nullptr);
}

inline void FinishPlayerInfoBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<PlayerInfo> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedPlayerInfoBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<PlayerInfo> root) {
  fbb.FinishSizePrefixed(root);
}

#endif  // FLATBUFFERS_GENERATED_TEST_H_
