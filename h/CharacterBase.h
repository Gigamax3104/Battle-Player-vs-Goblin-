#pragma once

class CharacterBase {
protected:
	virtual int Attack() = 0;

	virtual double Action() = 0;

	virtual void Item() = 0;

	virtual void Guard() = 0;

	virtual bool Dodge() = 0;

	virtual void Damage(int damage) = 0;

	virtual bool IsArive() const = 0;
};