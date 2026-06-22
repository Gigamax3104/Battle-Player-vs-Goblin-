#pragma once

class CharacterBase {
	virtual void Choice() = 0;

	virtual int Attack() = 0;

	virtual double Action() = 0;

	virtual void Item() = 0;

	virtual void Guard() = 0;

	virtual bool Dodge() = 0;

	virtual void Damage(int) = 0;

	virtual bool IsArive() const = 0;
};