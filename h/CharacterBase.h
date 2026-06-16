#pragma once

class CharacterBase {
protected:
	virtual int Attack() = 0; //攻撃

	virtual double Action() = 0; //行動

	virtual void Item() = 0; //アイテム

	virtual void Guard() = 0; //防御

	virtual bool Dodge() = 0; //回避

	virtual void Damage(int damage) = 0; //ダメージ

	virtual bool IsArive() const = 0; //生存チェック
};