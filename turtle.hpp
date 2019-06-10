#pragma once

#include <complex>
#include <unordered_map>

#include "datum/enum.hpp"
#include "datum/object.hpp"

#include "shape.hpp"

namespace WarGrey::SCADA {
	private enum class GreenTurtleAnchor { Home, _ };

	private class ITurtle abstract : public WarGrey::SCADA::SharedObject {
	public:
		void clear();
		void wipe();
		void fill_stepsize(float* xstep, float* ystep);
		Microsoft::Graphics::Canvas::Geometry::CanvasGeometry^ snap_path();
		Microsoft::Graphics::Canvas::Geometry::CanvasGeometry^ snap_track(float thickness = 1.0F,
			Microsoft::Graphics::Canvas::Geometry::CanvasStrokeStyle^ style = nullptr);

	protected:
		virtual ~ITurtle() noexcept {}
		ITurtle(float xstepsize, float ystepsize, bool big_turn, unsigned int start_anchor, unsigned int _anchor);

	protected:
		void fill_anchor_location(unsigned int anchor, float* x, float* y);
		void fill_anchors_distance(unsigned int anchor1, unsigned int anchor2, float* xdistance, float* ydistance);
		Microsoft::Graphics::Canvas::Geometry::CanvasGeometry^ subtrack(unsigned int a1, unsigned int a2,
			float thickness, Microsoft::Graphics::Canvas::Geometry::CanvasStrokeStyle^ style);

	protected:
		void move_to(unsigned int a_id);
		void jump_back(unsigned int a_id);

	protected:
		void jump_up(float step, unsigned int a_id);
		void jump_right(float step, unsigned int a_id);
		void jump_down(float step, unsigned int a_id);
		void jump_left(float step, unsigned int a_id);
		void jump_up_right(float xstep, float ystep, unsigned int a_id);
		void jump_right_down(float xstep, float ystep, unsigned int a_id);
		void jump_down_left(float xstep, float ystep, unsigned int a_id);
		void jump_left_up(float xstep, float ystep, unsigned int a_id);

	protected:
		void move_up(float step, unsigned int a_id);
		void move_right(float step, unsigned int a_id);
		void move_down(float step, unsigned int a_id);
		void move_left(float step, unsigned int a_id);
		void move_up_right(float xstep, float ystep, unsigned int a_id);
		void move_right_down(float xstep, float ystep, unsigned int a_id);
		void move_down_left(float xstep, float ystep, unsigned int a_id);
		void move_left_up(float xstep, float ystep, unsigned int a_id);

	protected:
		void turn_down_left(unsigned int a_id);
		void turn_left_down(unsigned int a_id);
		void turn_down_right(unsigned int a_id);
		void turn_right_down(unsigned int a_id);
		void turn_left_up(unsigned int a_id);
		void turn_up_left(unsigned int a_id);
		void turn_right_up(unsigned int a_id);
		void turn_up_right(unsigned int a_id);

	protected:
		void turn_down_left_up(unsigned int a_id);
		void turn_down_right_up(unsigned int a_id);
		void turn_up_left_down(unsigned int a_id);
		void turn_up_right_down(unsigned int a_id);
		void turn_left_down_right(unsigned int a_id);
		void turn_left_up_right(unsigned int a_id);
		void turn_right_down_left(unsigned int a_id);
		void turn_right_up_left(unsigned int a_id);

	protected:
		void drift(float xstep, float ystep, float xctrl_step, float yctrl_step, unsigned int a_id);
		void drift(float xstep, float ystep, unsigned int ctrl_id, unsigned int a_id);
		void drift(float xstep, float ystep, float xctrl1_step, float yctrl1_step, float xctrl2_step, float yctrl2_step, unsigned int a_id);
		void drift(float xstep, float ystep, unsigned int ctrl1_id, float xctrl2_step, float yctrl2_step, unsigned int a_id);
		void drift(float xstep, float ystep, float xctrl1_step, float yctrl1_step, unsigned int ctrl2_id, unsigned int a_id);
		void drift(float xstep, float ystep, unsigned int ctrl1_id, unsigned int ctrl2_id, unsigned int a_id);

		void drift_to(unsigned int a_id, float xctrl_step, float yctrl_step);
		void drift_to(unsigned int a_id, unsigned int ctrl_id);
		void drift_to(unsigned int a_id, float xctrl1_step, float yctrl1_step, float xctrl2_step, float yctrl2_step);
		void drift_to(unsigned int a_id, unsigned int ctrl1_id, float xctrl2_step, float yctrl2_step);
		void drift_to(unsigned int a_id, float xctrl1_step, float yctrl1_step, unsigned int ctrl2_id);
		void drift_to(unsigned int a_id, unsigned int ctrl1_id, unsigned int ctrl2_id);

	private:
		void do_rebuild();
		void do_step(unsigned int a_id);
		void do_anchor(unsigned int a_id);
		void do_jump(unsigned int a_id);
		void do_move(unsigned int a_id);
		void do_clockwise_turn(unsigned int a_id);
		void do_counterclockwise_turn(unsigned int a_id);
		void do_drift(float xctrl, float yctrl, unsigned int a_id);
		void do_drift(float xctrl1, float yctrl1, float xctrl2, float yctrl2, unsigned int a_id);

	private:
		Microsoft::Graphics::Canvas::Geometry::CanvasPathBuilder^ track;
		float xstepsize;
		float ystepsize;
		float xradius;
		float yradius;
		float x;
		float y;

	private:
		Microsoft::Graphics::Canvas::Geometry::CanvasGeometry^ snapshot;
		std::unordered_map<unsigned int, std::complex<float>> anchors;
		unsigned int last_backtrace_anchor;
		unsigned int _anchor;
		bool moved;
	}; 
	
	template<typename Anchor>
	private class Turtle final : public WarGrey::SCADA::ITurtle {
	public:
		Turtle(float xstepsize, float ystepsize, bool big_turn = false, Anchor start_anchor = Anchor::_)
			: WarGrey::SCADA::ITurtle(xstepsize, ystepsize, big_turn, _I(start_anchor), _I(Anchor::_)) {}

		Turtle(float stepsize, bool big_turn = false, Anchor start_anchor = Anchor::_)
			: WarGrey::SCADA::Turtle<Anchor>(stepsize, stepsize, big_turn, start_anchor) {}

	public:
		void fill_anchor_location(Anchor a, float* x, float* y) {
			WarGrey::SCADA::ITurtle::fill_anchor_location(_I(a), x, y);
		}

		void fill_anchors_distance(Anchor a1, Anchor a2, float* xdistance, float* ydistance) {
			WarGrey::SCADA::ITurtle::fill_anchors_distance(_I(a1), _I(a2), xdistance, ydistance);
		}

		Microsoft::Graphics::Canvas::Geometry::CanvasGeometry^ subtrack(Anchor a1, Anchor a2
			, float thickness = 1.0F, Microsoft::Graphics::Canvas::Geometry::CanvasStrokeStyle^ style = nullptr) {
			return WarGrey::SCADA::ITurtle::subtrack(_I(a1), _I(a2), thickness, style);
		}

		Microsoft::Graphics::Canvas::Geometry::CanvasGeometry^ subtrack(Anchor as[], unsigned int count
			, float thickness = 1.0F, Microsoft::Graphics::Canvas::Geometry::CanvasStrokeStyle^ style = nullptr) {
			Microsoft::Graphics::Canvas::Geometry::CanvasGeometry^ track = WarGrey::SCADA::blank();

			for (unsigned int idx = 0; idx < count - 1; idx++) {
				track = WarGrey::SCADA::geometry_union(track,
					WarGrey::SCADA::ITurtle::subtrack(_I(as[idx]), _I(as[idx + 1]), thickness, style));
			}

			return track;
		}

		template<size_t N>
		Microsoft::Graphics::Canvas::Geometry::CanvasGeometry^ subtrack(Anchor (&as)[N]
			, float thickness = 1.0F, Microsoft::Graphics::Canvas::Geometry::CanvasStrokeStyle^ style = nullptr) {
			return this->subtrack(as, N, thickness, style);
		}

	public:
		WarGrey::SCADA::Turtle<Anchor>* move_to(Anchor id) {
			WarGrey::SCADA::ITurtle::move_to(_I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_back(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::jump_back(_I(id));
			return this;
		}

	public:
		WarGrey::SCADA::Turtle<Anchor>* jump_up(Anchor id) {
			return this->jump_up(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_right(Anchor id) {
			return this->jump_right(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_down(Anchor id) {
			return this->jump_down(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_left(Anchor id) {
			return this->jump_left(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_up_right(Anchor id) {
			return this->jump_up_right(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_right_up(Anchor id) {
			return this->jump_up_right(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_right_down(Anchor id) {
			return this->jump_right_down(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_down_right(Anchor id) {
			return this->jump_right_down(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_down_left(Anchor id) {
			return this->jump_down_left(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_left_down(Anchor id) {
			return this->jump_down_left(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_left_up(Anchor id) {
			return this->jump_left_up(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_up_left(Anchor id) {
			return this->jump_left_up(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_up(int step = 1, Anchor id = Anchor::_) {
			return this->jump_up(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_right(int step = 1, Anchor id = Anchor::_) {
			return this->jump_right(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_down(int step = 1, Anchor id = Anchor::_) {
			return this->jump_down(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_left(int step = 1, Anchor id = Anchor::_) {
			return this->jump_left(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_up_right(int step = 1, Anchor id = Anchor::_) {
			return this->jump_up_right(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_right_up(int step = 1, Anchor id = Anchor::_) {
			return this->jump_up_right(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_right_down(int step = 1, Anchor id = Anchor::_) {
			return this->jump_right_down(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_down_right(int step = 1, Anchor id = Anchor::_) {
			return this->jump_right_down(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_down_left(int step = 1, Anchor id = Anchor::_) {
			return this->jump_down_left(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_left_down(int step = 1, Anchor id = Anchor::_) {
			return this->jump_down_left(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_left_up(int step = 1, Anchor id = Anchor::_) {
			return this->jump_left_up(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_up_left(int step = 1, Anchor id = Anchor::_) {
			return this->jump_left_up(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_right_up(float step, Anchor id = Anchor::_) {
			return this->jump_up_right(step, step, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_down_right(float step, Anchor id = Anchor::_) {
			return this->jump_right_down(step, step, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_left_down(float step, Anchor id = Anchor::_) {
			return this->jump_down_left(step, step, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_up_left(float step, Anchor id = Anchor::_) {
			return this->jump_left_up(step, step, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_right_up(float xstep, float ystep, Anchor id = Anchor::_) {
			return this->jump_up_right(xstep, ystep, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_down_right(float xstep, float ystep, Anchor id = Anchor::_) {
			return this->jump_right_down(xstep, ystep, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_left_down(float xstep, float ystep, Anchor id = Anchor::_) {
			return this->jump_down_left(xstep, ystep, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_up_left(float xstep, float ystep, Anchor id = Anchor::_) {
			return this->jump_left_up(xstep, ystep, id);
		}

	public:
		WarGrey::SCADA::Turtle<Anchor>* move_up(Anchor id) {
			return this->move_up(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_right(Anchor id) {
			return this->move_right(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_down(Anchor id) {
			return this->move_down(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_left(Anchor id) {
			return this->move_left(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_up_right(Anchor id) {
			return this->move_up_right(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_right_up(Anchor id) {
			return this->move_up_right(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_right_down(Anchor id) {
			return this->move_right_down(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_down_right(Anchor id) {
			return this->move_right_down(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_down_left(Anchor id) {
			return this->move_down_left(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_left_down(Anchor id) {
			return this->move_down_left(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_left_up(Anchor id) {
			return this->move_left_up(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_up_left(Anchor id) {
			return this->move_left_up(1.0F, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_up(int step = 1, Anchor id = Anchor::_) {
			return this->move_up(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_right(int step = 1, Anchor id = Anchor::_) {
			return this->move_right(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_down(int step = 1, Anchor id = Anchor::_) {
			return this->move_down(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_left(int step = 1, Anchor id = Anchor::_) {
			return this->move_left(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_up_right(int step = 1, Anchor id = Anchor::_) {
			return this->move_up_right(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_right_up(int step = 1, Anchor id = Anchor::_) {
			return this->move_up_right(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_right_down(int step = 1, Anchor id = Anchor::_) {
			return this->move_right_down(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_down_right(int step = 1, Anchor id = Anchor::_) {
			return this->move_right_down(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_down_left(int step = 1, Anchor id = Anchor::_) {
			return this->move_down_left(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_left_down(int step = 1, Anchor id = Anchor::_) {
			return this->move_down_left(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_left_up(int step = 1, Anchor id = Anchor::_) {
			return this->move_left_up(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_up_left(int step = 1, Anchor id = Anchor::_) {
			return this->move_left_up(float(step), id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_right_up(float step, Anchor id = Anchor::_) {
			return this->move_up_right(step, step, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_down_right(float step, Anchor id = Anchor::_) {
			return this->move_right_down(step, step, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_left_down(float step, Anchor id = Anchor::_) {
			return this->move_down_left(step, step, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_up_left(float step, Anchor id = Anchor::_) {
			return this->move_left_up(step, step, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_right_up(float xstep, float ystep, Anchor id = Anchor::_) {
			return this->move_up_right(xstep, ystep, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_down_right(float xstep, float ystep, Anchor id = Anchor::_) {
			return this->move_right_down(xstep, ystep, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_left_down(float xstep, float ystep, Anchor id = Anchor::_) {
			return this->move_down_left(xstep, ystep, id);
		}

		WarGrey::SCADA::Turtle<Anchor>* move_up_left(float xstep, float ystep, Anchor id = Anchor::_) {
			return this->move_left_up(xstep, ystep, id);
		}

	public:
		WarGrey::SCADA::Turtle<Anchor>* jump_up(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::jump_up(step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_right(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::jump_right(step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_down(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::jump_down(step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_left(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::jump_left(step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_up_right(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::jump_up_right(step, step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_right_down(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::jump_right_down(step, step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_down_left(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::jump_down_left(step, step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_left_up(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::jump_left_up(step, step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_up_right(float xstep, float ystep, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::jump_up_right(xstep, ystep, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_right_down(float xstep, float ystep, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::jump_right_down(xstep, ystep, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_down_left(float xstep, float ystep, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::jump_down_left(xstep, ystep, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* jump_left_up(float xstep, float ystep, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::jump_left_up(xstep, ystep, _I(id));
			return this;
		}

	public:
		WarGrey::SCADA::Turtle<Anchor>* move_up(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::move_up(step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* move_right(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::move_right(step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* move_down(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::move_down(step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* move_left(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::move_left(step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* move_up_right(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::move_up_right(step, step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* move_right_down(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::move_right_down(step, step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* move_down_left(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::move_down_left(step, step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* move_left_up(float step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::move_left_up(step, step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* move_up_right(float xstep, float ystep, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::move_up_right(xstep, ystep, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* move_right_down(float xstep, float ystep, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::move_right_down(xstep, ystep, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* move_down_left(float xstep, float ystep, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::move_down_left(xstep, ystep, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* move_left_up(float xstep, float ystep, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::move_left_up(xstep, ystep, _I(id));
			return this;
		}

	public:
		WarGrey::SCADA::Turtle<Anchor>* turn_down_left(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_down_left(_I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* turn_left_down(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_left_down(_I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* turn_down_right(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_down_right(_I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* turn_right_down(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_right_down(_I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* turn_left_up(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_left_up(_I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* turn_up_left(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_up_left(_I(id));
			return this;

		}

		WarGrey::SCADA::Turtle<Anchor>* turn_right_up(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_right_up(_I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* turn_up_right(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_up_right(_I(id));
			return this;
		}

	public:
		WarGrey::SCADA::Turtle<Anchor>* turn_down_left_up(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_down_left_up(_I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* turn_down_right_up(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_down_right_up(_I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* turn_up_left_down(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_up_left_down(_I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* turn_up_right_down(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_up_right_down(_I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* turn_left_down_right(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_left_down_right(_I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* turn_left_up_right(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_left_up_right(_I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* turn_right_down_left(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_right_down_left(_I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* turn_right_up_left(Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::turn_right_up_left(_I(id));
			return this;
		}

	public:
		WarGrey::SCADA::Turtle<Anchor>* drift(float xstep, float ystep, float xctrl_step, float yctrl_step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::drift(xstep, ystep, xctrl_step, yctrl_step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* drift(float xstep, float ystep, Anchor ctrl_id, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::drift(xstep, ystep, _I(ctrl_id), _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* drift(float xstep, float ystep, float xctrl1_step, float yctrl1_step, float xctrl2_step, float yctrl2_step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::drift(xstep, ystep, xctrl1_step, yctrl1_step, xctrl2_step, yctrl2_step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* drift(float xstep, float ystep, Anchor ctrl1_id, float xctrl2_step, float yctrl2_step, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::drift(xstep, ystep, _I(ctrl1_id), xctrl2_step, yctrl2_step, _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* drift(float xstep, float ystep,  float xctrl1_step, float yctrl1_step, Anchor ctrl2_id, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::drift(xstep, ystep, xctrl1_step, yctrl1_step, _I(ctrl2_id), _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* drift(float xstep, float ystep, Anchor ctrl1_id, Anchor ctrl2_id, Anchor id = Anchor::_) {
			WarGrey::SCADA::ITurtle::drift(xstep, ystep, _I(ctrl1_id), _I(ctrl2_id), _I(id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* drift_to(Anchor id, float xctrl_step, float yctrl_step) {
			WarGrey::SCADA::ITurtle::drift(_I(id), xctrl_step, yctrl_step);
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* drift_to(Anchor id, Anchor ctrl_id) {
			WarGrey::SCADA::ITurtle::drift_to(_I(id), _I(ctrl_id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* drift_to(Anchor id, float xctrl1_step, float yctrl1_step, float xctrl2_step, float yctrl2_step) {
			WarGrey::SCADA::ITurtle::drift_to(_I(id), xctrl1_step, yctrl1_step, xctrl2_step, yctrl2_step);
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* drift_to(Anchor id, Anchor ctrl1_id, float xctrl2_step, float yctrl2_step) {
			WarGrey::SCADA::ITurtle::drift_to(_I(id), _I(ctrl1_id), xctrl2_step, yctrl2_step);
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* drift_to(Anchor id, float xctrl1_step, float yctrl1_step, Anchor ctrl2_id) {
			WarGrey::SCADA::ITurtle::drift_to(_I(id), xctrl1_step, yctrl1_step, _I(ctrl2_id));
			return this;
		}

		WarGrey::SCADA::Turtle<Anchor>* drift_to(Anchor id, Anchor ctrl1_id, Anchor ctrl2_id) {
			WarGrey::SCADA::ITurtle::drift_to(_I(id), _I(ctrl1_id), _I(ctrl2_id));
			return this;
		}

	protected:
		virtual ~Turtle() noexcept {}
	};

	typedef WarGrey::SCADA::Turtle<GreenTurtleAnchor> GreenTurtle;
}
