#pragma once
#include "battle_game/core/unit.h"
#include "battle_game/core/units/tiny_tank.h"

namespace battle_game::unit {
class DoomTank : public Tank {
 public:
  DoomTank(GameCore *game_core, uint32_t id, uint32_t player_id);
  void Render() override;
  void Update() override;

 protected:
  bool IsHit(glm::vec2 position) const;
  void RandomDo();
  void Doomsday();
  void DestroyAll();
  void DoomTankUpdate();
  void Leech();
  void ToLeech();
  void Shield();
  void ToShield();
  uint32_t unit_id_{};
  uint32_t id_{0};
  bool is_leeched_ = false;
  bool is_shield_ = false;
  uint32_t doomsday_count_down_{0};
  uint32_t leech_count_down_{0};
  uint32_t leech_time_{240};
  uint32_t shield_count_down_{0};
  uint32_t shield_time_{180};
  double initial_health_;
  double begin_ = 1;
  double end_ = 0;
  double tmp_begin_;
  double tmp_end_;
  [[nodiscard]] const char *UnitName() const override;
  [[nodiscard]] const char *Author() const override;
};
}  // namespace battle_game::unit